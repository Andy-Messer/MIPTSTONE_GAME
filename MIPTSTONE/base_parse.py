from bs4 import BeautifulSoup
import requests as req
import os
import subprocess
import os.path
from tqdm import tqdm
import time

from threading import Thread


class ThreadingSchedule(object):
    flag = True

    def __init__(self, interval=1):
        self.interval = interval
        thread = Thread(target=self.run, args=())
        thread.daemon = True
        thread.start()

    def run(self):
        print("database downloading: ")
        for i in tqdm(range(1250)):
            time.sleep(0.9)


thread1 = ThreadingSchedule()


def Insert_Unit(url, N):
    resp = req.get(url)
    soup = BeautifulSoup(resp.text, 'lxml')
    name = soup.find('h1', id='firstHeading')
    dep = soup.find('li')
    param = soup.find_all('span', class_='starrating-avg')
    image_param = soup.find_all('tr')
    links = list()
    for i in image_param:
        links.append(i)

    global_values = list()
    global_name = str()
    global_departament = str()

    for i in name:
        global_name = str(i)

    if global_name[0] == N:
        mask = str()

        for i in dep:
            for j in i:
                tit = str(j.title()).strip()
                mask += tit

        global_departament = mask

        for attr in param:
            for i in attr:
                str_exc = str("( нет голосов )")
                if str(i) != str_exc:
                    global_values.append(str(i).split(' (')[0])
                else:
                    return False
        g = open('card_database.txt', 'a')
        for i in name:
            g.write(global_name + '\n')
        g.write(global_departament + '\n')
        # for i in global_values:
        #   f.write(i + '\n')
        for i in range(len(global_values) - 1):
            g.write(global_values[i] + '\n')
        g.write('\n')
        g.close()
        return True
    else:
        return -3


# Insert_Unit('http://wikimipt.org/wiki/%D0%9E%D1%81%D1%82%D0%B0%D0%BD%D0%B8%D0%BD_%D0%9F%D0%B0%D0%B2%D0%B5%D0%BB_%D0%90%D0%BD%D1%82%D0%BE%D0%BD%D0%BE%D0%B2%D0%B8%D1%87')
def parse_page(url):
    resp_global = req.get(url)
    soup_global = BeautifulSoup(resp_global.text, 'lxml')
    lib_names = soup_global.find(class_='mw-category').find_all('li')
    links = list()
    for i in lib_names:
        for j in i:
            links.append((str(j).split('"')[1]))

    N = url[-1]
    k = 1
    for i in range(2, len(links)):
        s = str(links[i])
        if not s.startswith('H'):
            print(k, ' downloaded \n')
            k += 1
            s = "http://wikimipt.org" + s + ""
            if Insert_Unit(s, N) == -3:
                return True
        # print(s)


def download():
    url = 'http://wikimipt.org/index.php?title=%D0%9A%D0%B0%D1%82%D0%B5%D0%B3%D0%BE%D1%80%D0%B8%D1%8F:%D0%9F%D1%80%D0%B5%D0%BF%D0%BE%D0%B4%D0%B0%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D0%B8_%D0%BF%D0%BE_%D0%B0%D0%BB%D1%84%D0%B0%D0%B2%D0%B8%D1%82%D1%83&from=%D0%91'
    main_resp = req.get(url)
    main_soup = BeautifulSoup(main_resp.text, 'lxml')
    lib = main_soup.find_all(class_="external text")
    list_lib = list()
    for i in lib:
        list_lib.append(i['href'])
    for i in range(1, len(list_lib)):
        parse_page(str(list_lib[i]))
    # print(str(list_lib[i]))
    thread1.run()


file_path = "base_parse.py"
if os.path.exists(file_path):
    pass
else:
    download()
