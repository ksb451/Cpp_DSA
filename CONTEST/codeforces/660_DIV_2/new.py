import requests
from bs4 import BeautifulSoup as bs

page_link = 'https://codeforces.com'
contest_code = 1388

result = requests.get(page_link+'/contest/'+str(contest_code))
print(result.status_code)

# print(result.headers)
soup = bs(result.content, 'lxml')
question_array = soup.find('table', class_='problems').find_all(class_='id')
for i in question_array:
    question_link = i.a['href']
    link = page_link+question_link
    ques_result = requests.get(link)
    q_soup = bs(ques_result.content, 'lxml')
    quescode = q_soup.find(class_="title").text.split('.')[0]
    sample = q_soup.find(class_="sample-tests")
    input_test = str(sample.find(class_='input').find('pre'))
    output_test = str(sample.find(class_='output').find('pre'))
    input_test = input_test.replace('<pre>\n', "")
    input_test = input_test.replace('</pre>', "")
    output_test = output_test.replace('<pre>\n', "")
    output_test = output_test.replace('</pre>', "")
    writefile = open(quescode+"in", "w")
    writefile.write(input_test)
    wf = open(quescode+'out', 'w')
    wf.write(output_test+'\n')
