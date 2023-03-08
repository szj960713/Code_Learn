from tkinter import *
from PIL import ImageTk
import time
import random as rd

heros = [['暗裔剑魔', '1.jpg', 180, 100, 150, 75], ['牛头酋长', '2.jpg', 180, 200, 100, 120],
            ['冰晶凤凰', '3.jpg', 270, 120, 180, 175], ['潮汐海灵', '4.jpg', 120, 160, 180, 240],
            ['扭曲树精', '5.jpg', 200, 160, 140, 290], ['迷失之牙', '6.jpg', 220, 160, 180, 190]]


root = Tk()
root.title('英雄之力')
root.geometry('460x300+700+300')

label = Label(root, width=460, height=300)
label.place(x=0, y=0)

text = StringVar()
text.set('请点击按钮')
l1 = Label(root,font=('黑体', 20), textvariable=text, background='white')
l1.place(x=50, y=20)

l2 = Label(root, background='white', text='物理攻击')
l2.place(x=50, y=80)
c1 = Canvas(root, background='white', width=300, height=22)
c1.place(x=120, y=80)

l3 = Label(root, background='white', text='魔法攻击')
l3.place(x=50, y=120)
c2 = Canvas(root, background='white', width=300, height=22)
c2.place(x=120, y=120)

l3 = Label(root, background='white', text='防御能力')
l3.place(x=50, y=160)
c3 = Canvas(root, background='white', width=300, height=22)
c3.place(x=120, y=160)

l3 = Label(root, background='white', text='上手难度')
l3.place(x=50, y=200)
c4 = Canvas(root, background='white', width=300, height=22)
c4.place(x=120, y=200)

def flush():
    c1.delete('all')
    c2.delete('all')
    c3.delete('all')
    c4.delete('all')
    info = heros[rd.randint(0, 5)]
    text.set(info[0])
    img = ImageTk.PhotoImage(file='d:/learn/python/英雄之力/' + info[1])
    label.config(image=img)
    label.image=img
    a = 0
    b = 0
    c = 0
    d = 0
    for i in range(100):
        a += info[2]/100
        b += info[3]/100
        c += info[4]/100
        d += info[5]/100
        c1.create_rectangle(0, 0, a, 22, width=0, fill='grey')
        c2.create_rectangle(0, 0, b, 22, width=0, fill='blue')
        c3.create_rectangle(0, 0, c, 22, width=0, fill='orange')
        c4.create_rectangle(0, 0, d, 22, width=0, fill='green')
        root.update()
        time.sleep(0.005)



btn = Button(root, text='查看属性', command=flush)
btn.place(x=200, y=240)




root.mainloop()