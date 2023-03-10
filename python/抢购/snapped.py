# edge 版本 111.0.5563.65（正式版本） （64 位）
# https://item.jd.com/10067605237369.html
from tkinter import *
from selenium.webdriver import Edge
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import datetime
import time

def Tip ():
    root = Tk()
    root.messagebox()
    root.mainloop()


def main ():
    # Edge_op = Options()
    # Edge_op.add_experimental_option("debuggerAddress", "127.0.0.1:9222")
    driver = Edge()
    driver.get('https://www.taobao.com/')
    time.sleep(2)
    driver.find_element(By.LINK_TEXT, "亲，请登录").click() 
    time.sleep(10)
    # 实际是可以操作的，单纯因为淘宝的人机验证有问题
    # driver.find_element(By.ID, "fm-login-id").send_keys(acc)
    # time.sleep(1)
    # driver.find_element(By.ID, "fm-login-password").send_keys(psd, Keys.ENTER)
    # time.sleep(2000)

    driver.get('https://cart.taobao.com/cart.htm')
    time.sleep(2)
    driver.find_element(By.ID, "J_SelectAll1").click()
    time.sleep(2)
    if driver.find_element(By.XPATH, "//a[@id=\"J_Go\"]"):
        driver.find_element(By.XPATH, "//a[@id=\"J_Go\"]").click()
    time.sleep(1)
    if driver.find_element(By.XPATH, "//a[@title=\"提交订单\"]"):
        driver.find_element(By.XPATH, "//a[@title=\"提交订单\"]").click()
    
    time.sleep(10000)
    # driver.quit()


if __name__ == '__main__':
    main()

