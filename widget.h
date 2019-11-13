#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QRect>
#include <QVBoxLayout>
#include <QPen>
#include <QPainter>
#include <QBrush>

#include <QTimerEvent>
#include <QPaintEvent>
#include <QTime>
#include <QTimer>

#include "process.h"
#include "memoryallocation.h"
#include <iostream>
#include <QString>


// 界面固定宽高
#define WIDTH 950
#define HEIGHT 540


// QPushButton 按钮样式表
#define BUTTON_STYLE_1 "QPushButton{ background-color:lightGray;font-family:FangSong;\
font-size:36px;border-radius:10px;border:1px} QPushButton:hover{ border-style:outset;}"
#define BUTTON_STYLE_2 "QPushButton{ background-color:lightGray;font-family:FangSong;\
font-size:18px;border-radius:10px;border:1px} QPushButton:hover{ border-style:outset;}"
#define BUTTON_STYLE_3 "QPushButton{ background-color:Gray;font-family:FangSong;\
font-size:18px;border-radius:10px;border:1px} QPushButton:hover{ border-style:outset;}"
#define BUTTON_STYLE_4 "QPushButton{ background-color:lightGray;font-family:FangSong;\
font-size:18px;border:1px} QPushButton:hover{ border-style:outset;}"
#define BUTTON_STYLE_5 "QPushButton{ background-color:Gray;font-family:FangSong;\
font-size:18px;border:1px} QPushButton:hover{ border-style:outset;}"

#define UPDATE_TIME 100 //刷新间隔
#define ONE_SECOND 1000//一个单位时间
#define RESERVED_BOUND  5//后备队列进程上界
#define RANDOM_REQUIRE_TIME_BOUND  9//随机生成的需求时间的上界
#define RANDOM_PRIORITY_BOUND  99//随机生成的优先级的上界
#define RANDOM_MEMORY_BOUND 199//随机生成的内存的上界

class Widget : public QWidget
{
    Q_OBJECT
    private:



        bool pause;//控制暂停开始
        int autoCreate;//自动创建作业情况
        Process* process[6];//内存中的进程
        int pcb[6]; //pcb使用情况
        int runningTotalTime;
        int time1,time2,time3;//控制计算时间

        Process* reservedHead;//后备队列中的进程头指针
        Process* reservedTail;//后备队列中的进程尾指针

        Process* runningProcess;

        MemoryAllocation* memoryAllocationHead;//内存分配管理头指针

     //全局设置模块

        QPushButton pauseButton;
        QPushButton closeButton;
        QPushButton noAutoButton;
        QPushButton oneTimeAutoButton;
        QPushButton twoTimeAutoButton;


    //正运行进程模块


        QLabel runningDescibe;
        QLabel runningName;
        QString nameDescibe;
        QLabel runningPcbLabel;
        QString pcbDescibe;
        QLabel runningPriorityLabel;
        QString priorityDescibe;
        QLabel runningMemoryLabel;
        QString memoryDescibe;
        QLabel runningTimeDescibe;

        QPushButton turnToWaitingButton;


    /*关于页面布局*/

    //创建进程模块
        QLabel createDescibe;
        QLabel createPriorityDescibe;
        QLabel createTimeDescibe;
        QLabel createMemoryDescibe;

        QLineEdit createPriorityInput;
        QLineEdit createTimeInput;
        QLineEdit createMemoryInput;

        QPushButton createButton;
        QPushButton resetButton;


   //挂起队列模块
        QLabel waitingDescibe;
        QLabel waitingTitle;
        QPushButton waitingShow[6];
        QPushButton turnToReadyButton;
        int waitingShowOfPCB[6];


     //就绪队列模块
        QLabel readyDescibe;
        QLabel readyTitle;
        QLabel readyShow[5];


   //后备队列模块
        QLabel reservedDescibe;
        QLabel reservedTitle;
        QLabel reservedShow[6];

  //内存展示条模块
        QLabel memoryStickDescibe;
        QLabel memoryAddressShow[12];
        QLabel memoryPCBShow[6];

   //未分配内存表模块
        QLabel memoryTableDescibe;
        QLabel memoryTableTitle;
        QLabel memoryShow[5];
        




    public:
        Widget(QWidget *parent = 0);
        ~Widget();

    private:

        void createNewProcessByRandom();//随机生成进程
        void createNewProcessByUser();//用户生成进程

        void updateReservedShow();//更新后备进程列表
        void updateRunningProcess();//更新正在运行的进程
        void updateReadyProcess();//更新就绪队列
        void updateWaitingProcess();//更新挂起队列
        void updateMemoryTable();//更新未分配表
        void updateMemoryStick();//更新内存条说明
        
        bool memoryAllocationJudge(Process* process);//判断内存空间是否足够
        bool  addReadyProcess(int i);//从后备队列调程序进入就绪队列


     protected:
        void timerEvent(QTimerEvent *event);
        void paintEvent(QPaintEvent *event);

    public slots:
        void pauseButtonClicked();
        void closeButtonClicked();
        void noAutoButtonClicked();
        void oneTimeAutoButtonClicked();
        void twoTimeAutoButtonClicked();

        void createButtonClicked();
        void resetButtonClicked();

        void waitingShow1Clicked();
        void waitingShow2Clicked();
        void waitingShow3Clicked();
        void waitingShow4Clicked();
        void waitingShow5Clicked();
        void waitingShow6Clicked();

        void turnToWaitingButtonClicked();
        void turnToReadyButtonClicked();






};

#endif // WIDGET_H
