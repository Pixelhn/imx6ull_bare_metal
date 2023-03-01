# EPIT

周期性中断定时器
32位**向下计数**

## 组成
时钟源

12位分频器

计数寄存器  CNR
加载寄存器  LR
比较寄存器  CMPR

中断 比较器

## 模式

set-and-forget
CNR计数到0后，从LR中获取新值

free-running
CNR计数到0后，从0XFF FF FF FF开计数

## 配置
CR:
    CLKSRC      时钟源选择
    PRESCALAR   分频器 0-4095
    RLD         工作模式
    OCIEN       比较中断使能
    EN          使能

SR
    OCIF        中断标志位