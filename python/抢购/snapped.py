# chrome 版本 111.0.5563.65（正式版本） （64 位）
# https://item.jd.com/10067605237369.html
from tkinter import *
from selenium import webdriver
from selenium.webdriver.common.by import By
import datetime
import time

def Tip ():
    root = Tk()
    root.geometry('300x100+400+200')
    l = Label(root, text='请完成登录')
    root.title('登录')
    l.pack()
    def ok ():
        root.destroy()
    btn = Button(root, text='好的',command=ok)
    btn.place(x=130, y=60)
    root.mainloop()


def main ():
    driver = webdriver.Chrome()
    driver.maximize_window()
    driver.get('https://www.taobao.com/')

    time.sleep(2)
    driver.find_element(By.XPATH, '//a[@class=\'h\']').click() 
    Tip()
    time.sleep(6)
    driver.get('https://cart.taobao.com/cart.htm')
    time.sleep(2)
    driver.find_element(By.ID, "J_CheckBoxShop").click()
    time.sleep(2)
    driver.find_element(By.ID, "J_Go")
    

    # driver.quit()


if __name__ == '__main__':
    main()

