import re

def detect_spanish_laughter(text):
    is_match = re.search("(([Jj][Aa]){1}){2,}", text)
    return bool(is_match)

def valid_phone(text):
    is_match = re.search("^(\+)?(359|0)(\d){9}", text)
    return bool(is_match)

def get_links(text):
    is_match = re.search("")
    return bool(is_match)


print(detect_spanish_laughter("Eres un burro jajaja"))
print(detect_spanish_laughter("JaJAjaJa!"))
print(detect_spanish_laughter("Ja wunderbar"))

print('////////')

print(valid_phone('+359885042893'))
print(valid_phone('112'))
print(valid_phone('359885042893'))
print(valid_phone('llama 359885042893 raccoon'))
print(valid_phone('0885042893'))

#print('//////')


















