import json
import random
import requests

def get_random_words(num_words):
    try:
        # Sending header to pretend like a browser because the website doesn't allow requests from scripts
        headers = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3"
        }
        response = requests.get("https://sozluk.gov.tr/autocomplete.json", headers=headers)

        if response.status_code == 200:
            data = json.loads(response.text)
            words = [entry['madde'] for entry in data]
            words = [word for word in words if " " not in word and word.isalpha()]
            words = [word.lower() for word in words]

            return random.sample(words, num_words)
        else:
            print("Error fetching data. Status code:", response.status_code)
            return []
    except requests.exceptions.RequestException as e:
        print("Request error:", e)
        return []

def write_words_to_file(words, filename):
    with open(filename, 'w', encoding='utf-8') as f:
        f.write('\n'.join(words))

def turkish_sort_key(word):
    order = 'abcçdefgğhıijklmnoöprsştuüvyz'
    return [order.index(c) for c in word if c in order]

def nearly_order(words, num_swaps):
    words = words.copy()
    for _ in range(num_swaps):
        i, j = random.sample(range(len(words)), 2)
        words[i], words[j] = words[j], words[i]
    return words

if __name__ == "__main__":
    random_words = get_random_words(10000)
    write_words_to_file(random_words, 'random_data.txt')

    ordered_words = sorted(random_words, key=turkish_sort_key)
    write_words_to_file(ordered_words, 'ordered_data.txt')
    
    nearly_ordered_words = nearly_order(ordered_words, 50)
    write_words_to_file(nearly_ordered_words, 'nearly_ordered_data.txt')