import wikipediaapi
import queue
import os

""" 
This script was used to construct the 270, 540 and 5400 datasets
"""

OUTPUT_DIRECTORY = "wikipedia_temp"
THREADS = [
    # animals
    "List of cat breeds",
    "Cat",
    "List of dog breeds",
    "Dog",
    "Animal",
    "Bird",
    # cs
    "Computer programming",
    "Python (programming language)",
    "C (programming language)",
    "Distributed computing",
    # geography
    "Barcelona",
    "United States",
    "European Union",
    "Frankfurt",
    "Nijmegen",
    "Denmark",
    "Sweden",
    "Africa",
    "Cape Town",
    # sports
    "Hockey",
    "Football",
    "Association football",
    "Ice skating",
    "Fencing",
    "Basketball",
    # food
    "Pa amb tomàquet",
    "Tortilla de patatas",
    "Watermelon",
    "Strawberry",
    "Banana",
    # people
    "Franz Kafka",
    "George Washington",
    "Miguel Milá",
    "Frank Lloyd Wright",
    "Antoni Gaudí",
    "Albert Einstein",
    "Tom Holland",
    "Marie Curie",
    "Cleopatra",
    "Hypatia",
    "Clara Campoamor",
    "Emily Wick",
    "Susan Solomon",
    # languages
    "Catalan language",
    "Spanish language",
    "English language",
    "German language",
    "French language",
    "Italian language",
    # religion
    "Catholic Church",
    "Confucianism",
    "Buddhism",
    "Islam",
    "Judaism",
    "Hinduism",
]


def save_article(index, title, text, directory=OUTPUT_DIRECTORY):
    if not os.path.exists(directory):
        os.makedirs(directory)
    filename = os.path.join(directory, f"{index}.txt")
    with open(filename, "w", encoding="utf-8") as file:
        file.write(f"{index}\n{title}\n{text}")


def load_visited_from_fs(directory=OUTPUT_DIRECTORY):
    visited = {}
    if not os.path.exists(directory):
        return -1, visited
    i = 0
    while True:
        filename = os.path.join(directory, f"{i}.txt")
        try:
            with open(filename, "r", encoding="utf-8") as file:
                visited[file.readline().strip("\n")] = i
        except FileNotFoundError:
            return i - 1, visited
        i += 1


def bfs_crawl(start_pages, max_articles=100):
    wiki_wiki = wikipediaapi.Wikipedia(
        f"SlowEducationCrawlerBot/0.0 ({input('url of your repository in github: ')})"
    )
    last_assigned, visited = load_visited_from_fs()
    q = queue.Queue()

    # Start BFS from the given start page
    for start_page in start_pages:
        visited_per_start_page = 0
        start = wiki_wiki.page(start_page)
        last_assigned += 1
        q.put((last_assigned, start))
        visited[start_page] = last_assigned

        while not q.empty():
            index, current_page = q.get()
            rc = 0
            while rc < 5:
                try:
                    text = current_page.text
                except Exception as e:
                    print(index, current_page, e)
                    rc += 1
                else:
                    break

            text = text.replace("[", "").replace("]", "")
            for link_title in current_page.links.keys():
                if link_title not in visited:
                    if visited_per_start_page + 1 < max_articles:
                        last_assigned += 1
                        visited_per_start_page += 1
                        visited[link_title] = last_assigned
                        q.put((last_assigned, wiki_wiki.page(link_title)))
                        text = text.replace(
                            link_title, f"[{link_title}]({last_assigned})"
                        )
                else:
                    text = text.replace(
                        link_title, f"[{link_title}]({visited[link_title]})"
                    )
            save_article(index, current_page.title, text)


if __name__ == "__main__":
    # wikipedia5400
    # bfs_crawl(THREADS, max_articles=100)

    # wikipedia540
    # bfs_crawl(THREADS, max_articles=10)

    # wikipedia270
    bfs_crawl(THREADS, max_articles=5)
