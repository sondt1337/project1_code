#PYTHON 
def cntword(text):
    words = text.split()
    word_count = len(words)
    return word_count
result = 0
while True: 
    try:    
        input_text = input()
        result += cntword(input_text)
    except EOFError:
        break
print(result)
