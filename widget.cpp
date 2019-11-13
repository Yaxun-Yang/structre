#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    //页面一些量的初始化
    setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(WIDTH,HEIGHT);

    /*全局设置模块*/
{
    //关闭按钮
    closeButton.setParent(this);
    closeButton.setText(tr("关闭"));
    closeButton.setGeometry(40,10,80,65);
    closeButton.setStyleSheet(BUTTON_STYLE_1);
    connect(&closeButton,SIGNAL(clicked(bool)),this,SLOT(closeButtonClicked()));

   //开始暂停按钮
    pause = true;
    pauseButton.setParent(this);
    pauseButton.setText(tr("开始"));
    pauseButton.setGeometry(130,10,80,65);
    pauseButton.setStyleSheet(BUTTON_STYLE_1);
    connect(&pauseButton,SIGNAL(clicked(bool)),this,SLOT(pauseButtonClicked()));

    autoCreate = 1;//自动创建作业情况

    //不自动创建作业按钮
    noAutoButton.setParent(this);
    noAutoButton.setText(tr("不自动创建作业"));
    noAutoButton.setGeometry(35,95,180,35);
    noAutoButton.setStyleSheet(BUTTON_STYLE_2);
    connect(&noAutoButton,SIGNAL(clicked(bool)),this,SLOT(noAutoButtonClicked()));

    //一倍速自动创建作业按钮
    oneTimeAutoButton.setParent(this);
    oneTimeAutoButton.setText(tr("一倍速自动创建作业"));
    oneTimeAutoButton.setGeometry(35,150,180,35);
    oneTimeAutoButton.setStyleSheet(BUTTON_STYLE_3);
    connect(&oneTimeAutoButton,SIGNAL(clicked(bool)),this,SLOT(oneTimeAutoButtonClicked()));

    //两倍速自动创建作业按钮
    twoTimeAutoButton.setParent(this);
    twoTimeAutoButton.setText(tr("两倍速自动创建作业"));
    twoTimeAutoButton.setGeometry(35,205,180,35);
    twoTimeAutoButton.setStyleSheet(BUTTON_STYLE_2);
    connect(&twoTimeAutoButton,SIGNAL(clicked(bool)),this,SLOT(twoTimeAutoButtonClicked()));
}


    /*正运行进程模块*/
{
    //模块描述标签
    runningDescibe.setParent(this);
    runningDescibe.setFont(QFont("FangSong",12,100));
    runningDescibe.setGeometry(280,18,120,50);
    runningDescibe.setText("正在运行的进程");

    //名称标签
    runningName .setParent(this);
    runningName.setFont(QFont("Microsoft YaHei",12,100));
    runningName.setGeometry(260,50,180,30);
    nameDescibe =QString("名称：");
    runningName.setText(nameDescibe);

    //pcb标签
    runningPcbLabel .setParent(this);
    runningPcbLabel.setFont(QFont("Microsoft YaHei",12,100));
    runningPcbLabel.setGeometry(260,70,180,30);
    pcbDescibe =QString("PCB指针号：");
    runningPcbLabel.setText(pcbDescibe);

    //优先级标签
    runningPriorityLabel.setParent(this);
    runningPriorityLabel.setFont(QFont("Microsoft YaHei",12,100));
    runningPriorityLabel.setGeometry(260,90,180,30);
    priorityDescibe =QString("优先级：");
    runningPriorityLabel.setText(priorityDescibe);

    //内存标签
    runningMemoryLabel.setParent(this);
    runningMemoryLabel.setFont(QFont("Microsoft YaHei",12,100));
    runningMemoryLabel.setGeometry(260,110,200,30);
    memoryDescibe =QString("所占内存：");
    runningMemoryLabel.setText(memoryDescibe);

    //运行时间标签
    runningTimeDescibe.setParent(this);
    runningTimeDescibe.setFont(QFont("Microsoft YaHei",12,100));
    runningTimeDescibe.setGeometry(300,140,180,30);
    runningTimeDescibe.setText("剩余运行时间");

    //运行进程挂起按钮
    turnToWaitingButton.setParent(this);
    turnToWaitingButton.setText(tr("挂起"));
    turnToWaitingButton.setGeometry(330,210,40,30);
    turnToWaitingButton.setStyleSheet(BUTTON_STYLE_2);
    connect(&turnToWaitingButton,SIGNAL(clicked(bool)),this,SLOT(turnToWaitingButtonClicked()));
}


    /*创建进程模块*/
{
    //模块描述标签
    createDescibe.setParent(this);
    createDescibe.setFont(QFont("FangSong",12,100));
    createDescibe.setGeometry(515,15,150,50);
    createDescibe.setText("创建新的作业");

    //优先级描述标签
    createPriorityDescibe.setParent(this);
    createPriorityDescibe.setFont(QFont("Microsoft YaHei",10,100));
    createPriorityDescibe.setGeometry(480,65,50,15);
    createPriorityDescibe.setText("优先级");

    //优先级输入框
    createPriorityInput.setParent(this);
    createPriorityInput.setGeometry(550,60,120,20);
    createPriorityInput.setPlaceholderText(QString("请输入一个整数"));
    createPriorityInput.setMaxLength(2);
    createPriorityInput.setFont(QFont("FangSong",9,50));

    //时间描述标签
    createTimeDescibe .setParent(this);
    createTimeDescibe.setFont(QFont("Microsoft YaHei",10,100));
    createTimeDescibe.setGeometry(480,90,80,15);
    createTimeDescibe.setText("运行时间");

    //时间输入框
    createTimeInput.setParent(this);
    createTimeInput.setGeometry(550,85,120,20);
    createTimeInput.setPlaceholderText(QString("请输入一个整数"));
    createTimeInput.setMaxLength(2);
    createTimeInput.setFont(QFont("FangSong",9,50));

    //内存描述标签
    createMemoryDescibe .setParent(this);
    createMemoryDescibe.setFont(QFont("Microsoft YaHei",10,100));
    createMemoryDescibe.setGeometry(480,115,80,15);
    createMemoryDescibe.setText("所需内存");

    //内存输入框
    createMemoryInput.setParent(this);
    createMemoryInput.setGeometry(550,110,120,20);
    createMemoryInput.setPlaceholderText(QString("请输入一个整数"));
    createMemoryInput.setMaxLength(2);
    createMemoryInput.setFont(QFont("FangSong",9,50));
    //重置按钮
    resetButton.setParent(this);
    resetButton.setText(tr("重置"));
    resetButton.setGeometry(530,170,120,30);
    resetButton.setStyleSheet(BUTTON_STYLE_2);
    connect(&resetButton,SIGNAL(clicked(bool)),this,SLOT(resetButtonClicked()));

    //创建按钮
    createButton.setParent(this);
    createButton.setText(tr("创建"));
    createButton.setGeometry(530,210,120,30);
    createButton.setStyleSheet(BUTTON_STYLE_2);
    connect(&createButton,SIGNAL(clicked(bool)),this,SLOT(createButtonClicked()));
}


    /*挂起队列模块*/
{
    //模块描述标签
    waitingDescibe .setParent(this);
    waitingDescibe.setFont(QFont("FangSong",12,100));
    waitingDescibe.setGeometry(30,285,180,30);
    waitingDescibe.setText("被挂起的进程");

    //挂起队列表头
    waitingTitle .setParent(this);
    waitingTitle.setFont(QFont("Microsoft YaHei",10,80));
    waitingTitle.setGeometry(30,300,250,40);
    waitingTitle.setText("PID |PCB|优先级|剩余时间|所占内存");

    //展示标签初始化
    for(int i=0 ;i<6;i++)
    {
         waitingShow[i].setParent(this);
         waitingShow[i].setFont(QFont("Microsoft YaHei",11,100));
         waitingShow[i].setGeometry(30,340+i*30,220,30);
         waitingShow[i].setStyleSheet(BUTTON_STYLE_4);
         waitingShow[i].hide();
    }
    connect(&waitingShow[0],SIGNAL(clicked(bool)),this,SLOT(waitingShow1Clicked()));
    connect(&waitingShow[1],SIGNAL(clicked(bool)),this,SLOT(waitingShow2Clicked()));
    connect(&waitingShow[2],SIGNAL(clicked(bool)),this,SLOT(waitingShow3Clicked()));
    connect(&waitingShow[3],SIGNAL(clicked(bool)),this,SLOT(waitingShow4Clicked()));
    connect(&waitingShow[4],SIGNAL(clicked(bool)),this,SLOT(waitingShow5Clicked()));
    connect(&waitingShow[5],SIGNAL(clicked(bool)),this,SLOT(waitingShow6Clicked()));


    //解挂按钮
    turnToReadyButton .setParent(this);
    turnToReadyButton.setText(tr("解挂"));
    turnToReadyButton.setGeometry(45,495,60,30);
    turnToReadyButton.setStyleSheet(BUTTON_STYLE_2);
    connect(&turnToReadyButton,SIGNAL(clicked(bool)),this,SLOT(turnToReadyButtonClicked()));
}


    /*就绪队列模块*/
{
    //模块描述标签
    readyDescibe .setParent(this);
    readyDescibe.setFont(QFont("FangSong",12,100));
    readyDescibe.setGeometry(260,285,180,30);
    readyDescibe.setText("就绪的进程");

    //就绪表头
    readyTitle.setParent(this);
    readyTitle.setFont(QFont("Microsoft YaHei",10,100));
    readyTitle.setGeometry(260,300,250,40);
    readyTitle.setText("PID|PCB|优先级|剩余时间|所占内存");

    //展示标签初始化
    for(int i=0 ;i<5;i++)
    {
         readyShow[i].setParent(this);
         readyShow[i].setFont(QFont("Microsoft YaHei",11,100));
         readyShow[i].setGeometry(260,325+i*30,180,30);
         readyShow[i].show();
    }
}


    /*后备进程模块*/
{
    //模块描述标签
    reservedDescibe.setParent(this);
    reservedDescibe.setFont(QFont("FangSong",12,100));
    reservedDescibe.setGeometry(485,285,200,30);
    reservedDescibe.setText("后备的进程(显示前六个)");

    //后备表头
    reservedTitle.setParent(this);
    reservedTitle.setFont(QFont("Microsoft YaHei",10,100));
    reservedTitle.setGeometry(485,300,200,40);
    reservedTitle.setText(" PID |优先级|剩余时间|所需内存");

    //展示标签初始化
    for(int i=0 ;i<6;i++)
    {
         reservedShow[i].setParent(this);
         reservedShow[i].setFont(QFont("Microsoft YaHei",11,100));
         reservedShow[i].setGeometry(485,325+i*30,230,30);
         reservedShow[i].show();
    }
}

    /*内存展示条模块*/
    {
        //模块描述标签
        memoryStickDescibe.setParent(this);
        memoryStickDescibe.setFont(QFont("FangSong",12,100));
        memoryStickDescibe.setGeometry(735,15,200,50);
        memoryStickDescibe.setText("内存状态");

        //pcb指向初始化
        for(int i=0;i<6;i++)
        {
            memoryPCBShow[i].setParent(this);
            memoryPCBShow[i].setFont(QFont("Microsoft YaHei",11,50));
        }

        for(int i=0;i<12;i++)
        {
            memoryAddressShow[i].setParent(this);
            memoryAddressShow[i].setFont(QFont("Microsoft YaHei",11,50));
        }
    }

    /*未分分区表模块*/
    {
        //模块描述标签
        memoryTableDescibe.setParent(this);
        memoryTableDescibe.setFont(QFont("FangSong",12,100));
        memoryTableDescibe.setGeometry(735,285,200,30);
        memoryTableDescibe.setText("未分分区表");

        //未分区表表头
        memoryTableTitle.setParent(this);
        memoryTableTitle.setFont(QFont("Microsoft YaHei",10,100));
        memoryTableTitle.setGeometry(735,300,200,40);
        memoryTableTitle.setText("序号|   起始地址    |  空间大小  ");

        //展示标签初始化
        for(int i=0 ;i<5;i++)
        {
             memoryShow[i].setParent(this);
             memoryShow[i].setFont(QFont("Microsoft YaHei",11,100));
             memoryShow[i].setGeometry(735,325+i*30,180,30);
             memoryShow[i].show();
        }
    }

    /*业务逻辑*/
{
    runningProcess = nullptr;

    //初始化PCB指针
    for(int i=0 ; i<6; i++)
    {
        pcb[i] = 0;
    }
    //初始化挂起队列描述标签对应的PCB
    for(int i=0;i<6;i++)
    {
        waitingShowOfPCB[i] = -1;
    }
    //初始化程序指向
    for(int i=0;i<6;i++)
    {
        process[i] = nullptr;
    }

    //自动创建后备队列进程时间间隔
    time1=2*ONE_SECOND;
    time1=startTimer(time1);
    time2=startTimer(UPDATE_TIME);

    //后备队列相关
    reservedHead = reservedTail = nullptr;
    
    //分区管理初始化
    memoryAllocationHead = new MemoryAllocation();
    memoryAllocationHead->setInitialAddress(0);
    memoryAllocationHead->setMemorySize(200);
    
}

}
//时间更新事件
void Widget::timerEvent(QTimerEvent *event)
{
    if(!pause&&autoCreate&&time1 == event->timerId() )
    {
          createNewProcessByRandom();
    }
    if(!pause&&time2 == event->timerId())
    {
        updateReservedShow();
        updateReadyProcess();
        updateRunningProcess();
        updateWaitingProcess();
        updateMemoryTable();
        updateMemoryStick();
        this->update();
    }
}
//绘画事件
void Widget::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    QPen pen(Qt::gray,5,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    QBrush brush(Qt::gray,Qt::SolidPattern);



    painter.setPen(pen);
    painter.drawRect(QRect(260,170,180,30));
    painter.drawRect(QRect(800,60,50,200));
    painter.setBrush(brush);
    if(runningProcess!=nullptr)
    {
        painter.drawRect(QRect(260,170,(runningProcess->getTimeRequired()*180)/runningTotalTime,30));
       // printf("%d %d",runningProcess->getTimeRequired(),runningTotalTime);

    }
    for(int i=0;i<6;i++)
    {
         if(process[i] != nullptr)
         {
           //  qDebug("%d %d %d\n",i,process[i]->getInitialAddress(),process[i]->getMemorySize());
             painter.drawRect(QRect(800,60+process[i]->getInitialAddress(),50,process[i]->getMemorySize()));
         }
    }
   
 }

//判断程序是否能够进入内存
bool Widget::memoryAllocationJudge(Process * process)
{
    MemoryAllocation * pnow = memoryAllocationHead;
    while(pnow != nullptr)
    {
        if(pnow->getProcess() == nullptr&&pnow->getMemorySize()>=process->getMemorySize())
        {
            MemoryAllocation *pnow2 = new MemoryAllocation();
            pnow2->setInitialAddress(pnow->getInitialAddress());
            pnow2->setLastMemoryAllocation(pnow->getLastMemoryAllocation());
            pnow2->setProcess(process);
            pnow2->setMemorySize(process->getMemorySize());
            pnow2->getProcess()->setInitialAddress(pnow2->getInitialAddress());
            if(pnow == memoryAllocationHead)
            {
                memoryAllocationHead = pnow2;
            }
            else
            {
                pnow->getLastMemoryAllocation()->setNextMemoryAllocation(pnow2);
            }
            if(pnow->getMemorySize()==process->getMemorySize())
            {
                 pnow2->setLastMemoryAllocation(pnow->getLastMemoryAllocation());
                 if(pnow->getNextMemoryAllocation()!=nullptr)
                 {
                     pnow->getNextMemoryAllocation()->setLastMemoryAllocation(pnow2);
                 }
            }
            else
            {
                pnow2->setNextMemoryAllocation(pnow);
                pnow->setLastMemoryAllocation(pnow2);
                pnow->setInitialAddress(pnow2->getInitialAddress()+pnow2->getMemorySize());
                pnow->setMemorySize(pnow->getMemorySize()-pnow2->getMemorySize());
            }
         //   memoryAllocationOfPCB[process->getPcb()]=pnow2;
           return true;
        }
        pnow=pnow->getNextMemoryAllocation();
    }
    return false;
}

//随机生成进程
void Widget::createNewProcessByRandom()
{
    if(reservedHead==nullptr)
    {
        reservedHead = reservedTail = new Process(true);
    }
    else
    {
        reservedTail->setNextProcess(new Process(true));
        reservedTail = reservedTail->getNextProcess();
    }
    reservedTail -> setPriority(qrand()%RANDOM_PRIORITY_BOUND + 1);
    reservedTail -> setTimeRequired(qrand()%RANDOM_REQUIRE_TIME_BOUND +1);
    reservedTail ->setMemorySize(qrand()%RANDOM_MEMORY_BOUND +1);
}

void Widget::createNewProcessByUser()
{
    if(reservedHead==nullptr)
    {
        reservedHead = reservedTail = new Process(false);
    }
    else
    {
        reservedTail->setNextProcess(new Process(false));
        reservedTail = reservedTail->getNextProcess();
    }
    QString text=createPriorityInput.text();
    reservedTail -> setPriority(text.toInt());
    text=createTimeInput.text();
    reservedTail -> setTimeRequired(text.toInt());
    text=createMemoryInput.text();
    reservedTail -> setMemorySize(text.toInt());
}

void Widget::updateReservedShow()
{
    Process * Pnow = reservedHead;

    for(int i=0 ; i<6 ; i++)
    {

        if(Pnow != nullptr)
        {
            QString str;
            if(Pnow->getIfRandom())
                str = "Random";
            else
                str = "User  ";
            str.append(QString::number(Pnow->getPid(),10));
            str.append("  ");
            str.append(QString::number(Pnow->getPriority(),10));
            str.append("    ");
            str.append(QString::number(Pnow->getTimeRequired()/10,10));
            str.append("    ");
            str.append(QString::number(Pnow->getMemorySize(),10));
            str.append("MB");
            reservedShow[i].setText(str);
            Pnow = Pnow->getNextProcess();
        }
        else
        {
            reservedShow[i].setText("");
        }

    }
}

void Widget::updateRunningProcess()
{
    if(runningProcess == nullptr || runningProcess->getTimeRequired()<=0)
    {
        if(runningProcess != nullptr)
        {
            if(!addReadyProcess(runningProcess->getPcb()))
            {
                pcb[runningProcess->getPcb()]=0; 
                process[runningProcess->getPcb()]=nullptr;
            }
            MemoryAllocation* pnow = memoryAllocationHead;
            while(pnow!=nullptr&&pnow->getProcess()!=runningProcess)
            {
                pnow=pnow->getNextMemoryAllocation();
            }
         //   qDebug("%d\n",pnow->getProcess()->getPcb());
            pnow->setProcess(nullptr);
            if(pnow->getLastMemoryAllocation()!=nullptr&&pnow->getLastMemoryAllocation()->getProcess()==nullptr)
            {
                pnow=pnow->getLastMemoryAllocation();
                pnow->setMemorySize(pnow->getMemorySize()+pnow->getNextMemoryAllocation()->getMemorySize());
                pnow->setNextMemoryAllocation(pnow->getNextMemoryAllocation()->getNextMemoryAllocation());
                if(pnow->getNextMemoryAllocation()!=nullptr)
                {
                    pnow->getNextMemoryAllocation()->getLastMemoryAllocation()->~MemoryAllocation();
                    pnow->getNextMemoryAllocation()->setLastMemoryAllocation(pnow);
                }

            }
            if(pnow->getNextMemoryAllocation()!=nullptr&&pnow->getNextMemoryAllocation()->getProcess()==nullptr)
            {
                pnow=pnow->getNextMemoryAllocation();
                pnow->setMemorySize(pnow->getMemorySize()+pnow->getLastMemoryAllocation()->getMemorySize());
                pnow->setInitialAddress(pnow->getLastMemoryAllocation()->getInitialAddress());
                pnow->setLastMemoryAllocation(pnow->getLastMemoryAllocation()->getLastMemoryAllocation());
                if(pnow->getLastMemoryAllocation()!=nullptr)
                {
                    pnow->getLastMemoryAllocation()->getNextMemoryAllocation()->~MemoryAllocation();
                    pnow->getLastMemoryAllocation()->setNextMemoryAllocation(pnow);
                }
                else
                {
                    memoryAllocationHead=pnow;
                }
            }

            runningProcess->~Process();
            runningProcess=nullptr;
        }

        int Pnow = 7;
        for(int i=0 ; i<6 ; i++)
         if(pcb[i] == 1)
        {
            if(Pnow == 7||process[Pnow]->getPriority()<process[i]->getPriority())
            {
                Pnow = i;
            }
        }
        if(Pnow!=7)
        {
            pcb[Pnow] = 2;
            runningProcess=process[Pnow];

            runningTotalTime=runningProcess->getTimeRequired();
            runningProcess->SubPriority();
            runningProcess->SubTime();
        }

    }
    else
    {
        runningProcess->SubTime();
    }
     nameDescibe =QString("名称：");
     pcbDescibe = QString("PCB指针号：");
     priorityDescibe =QString("优先级：");
     memoryDescibe =QString("所占内存： ");
    if(runningProcess != nullptr)
    {
        if(runningProcess->getIfRandom())
            nameDescibe.append("Random");
        else
            nameDescibe.append("User");
        nameDescibe.append(QString::number(runningProcess->getPid(),10));
        pcbDescibe.append(QString::number(runningProcess->getPcb(),10));
        priorityDescibe.append(QString::number(runningProcess->getPriority(),10));
        memoryDescibe.append(QString::number(runningProcess->getMemorySize(),10));
        memoryDescibe.append("MB");
    }
    runningName.setText(nameDescibe);
    runningPcbLabel.setText(pcbDescibe);
    runningPriorityLabel.setText(priorityDescibe);
    runningMemoryLabel.setText(memoryDescibe);
}

void Widget::updateReadyProcess()
{

    bool judge[6];
    int k = 0;
    for(int i=0 ; i<6 ; i++)
    {
        if(pcb[i] == 0)
        {
           addReadyProcess(i);
        }
        if(pcb[i]!=1)
        {
            judge[i] = false;
        }
        else
        {
            judge[i] = true;
            k++;
        }
    }

    for(int i=0 ; i<5 ; i++)
    if(i < k )
    {
        int  Pnow =7;
       for(int j=0;j<6;j++)
           if(judge[j])
           {
               if(Pnow == 7 ||process[Pnow]->getPriority()<process[j]->getPriority() )
               {
                   Pnow = j;
               }
           }
       judge [Pnow] = false;
       QString str;
       if(process[Pnow]->getIfRandom())
       {
           str = "Random";
       }
       else
       {
           str = "User  ";
       }
       str.append(QString::number(process[Pnow]->getPid(),10));
       str.append(" ");
       str.append(QString::number(process[Pnow]->getPcb(),10));
       str.append(" ");
       str.append(QString::number(process[Pnow]->getPriority(),10));
       str.append(" ");
       str.append(QString::number(process[Pnow]->getTimeRequired()/10,10));
       str.append(" ");
       str.append(QString::number(process[Pnow]->getMemorySize(),10));
       str.append("MB");
       readyShow[i].setText(str);
    }
    else
    {
        readyShow[i].setText("");
    }

}

void Widget::updateWaitingProcess()
{
    int k=0;
    for(int i=0;i<6;i++)
    if(pcb[i]==3||pcb[i]==4)
    {
        QString str;
        if(process[i]->getIfRandom())
        {
            str = "Random";
        }
        else
        {
            str = "User  ";
        }
        str.append(QString::number(process[i]->getPid(),10));
        str.append(" ");
        str.append(QString::number(process[i]->getPcb(),10));
        str.append(" ");
        str.append(QString::number(process[i]->getPriority(),10));
        str.append(" ");
        str.append(QString::number(process[i]->getTimeRequired()/10,10));
        str.append("");
        str.append(QString::number(process[i]->getMemorySize(),10));
        str.append("MB");
        waitingShow[k].setText(str);
        waitingShow[k].show();
        waitingShowOfPCB[k]=process[i]->getPcb();
        k++;
    }
    for(;k<6;k++)
    {
        waitingShow[k].hide();
        waitingShowOfPCB[k]=-1;
    }

}

void Widget::updateMemoryTable()
{
    MemoryAllocation* pnow = memoryAllocationHead;
    int i=0;
   while(pnow!=nullptr)
   {
       if(pnow->getProcess()==nullptr)
       {
           QString str="  ";
           str.append(QString::number(i,10));
           str.append("         ");
           str.append(QString::number(pnow->getInitialAddress(),10));
           str.append("           ");
           str.append(QString::number(pnow->getMemorySize(),10));
           memoryShow[i].setText(str);
           i++;
       }
       pnow=pnow->getNextMemoryAllocation();
   }
   for(;i<5;i++)
   {
       memoryShow[i].setText("");
   }
}

void Widget::updateMemoryStick()
{
    for(int i=0;i<6;i++)
    {
        if(process[i]!=nullptr)
        {
            QString str="PCB ";
            str.append(QString::number(process[i]->getPcb(),10));
            str.append("->");
            memoryPCBShow[i].setGeometry(740,50+process[i]->getInitialAddress()+process[i]->getMemorySize()/2,100,20);
            memoryPCBShow[i].setText(str);
            memoryPCBShow[i].show();
        }
        else
        {
            memoryPCBShow[i].setText("");
        }
    }
    MemoryAllocation* pnow=memoryAllocationHead;
    int i=0;
    while(pnow)
    {
       memoryAddressShow[i].setGeometry(850,50+pnow->getInitialAddress(),100,20);
       QString str="<-";
       str.append(QString::number(pnow->getInitialAddress(),10));
       memoryAddressShow[i].setText(str);
       pnow=pnow->getNextMemoryAllocation();
       i++;
    }
    memoryAddressShow[i].setGeometry(850,250,100,20);
    QString str="<-";
    str.append(QString::number(200,10));
    memoryAddressShow[i].setText(str);
    i++;
    for(;i<12;i++)
        memoryAddressShow[i].setText("");
}

void Widget::turnToWaitingButtonClicked()
{
    int num=runningProcess->getPcb();
    runningProcess=nullptr;
    pcb[num]=3;
}

void Widget::turnToReadyButtonClicked()
{
    for(int i=0;i<6;i++)
    {
        int num=waitingShowOfPCB[i];
        if(num == -1) break;
       if(pcb[num]==4)
       {
           pcb[num]=1;
       }
       waitingShow[i].setStyleSheet(BUTTON_STYLE_4);
    }
}

//关闭按钮
void Widget::closeButtonClicked()
{
    this->close();
}
//停止与开始按钮
void Widget::pauseButtonClicked()
{
    pause = !pause;
   if(pause)
   {
       pauseButton.setText(tr("开始"));
   }
   else
    {
       pauseButton.setText(tr("停止"));
   }
}

Widget::~Widget()
{

}

bool Widget::addReadyProcess(int i)
{
    Process * firstProcess = reservedHead;
    Process * secondProcess = nullptr;
    while(firstProcess&&!memoryAllocationJudge(firstProcess))
    {
        secondProcess=firstProcess;
        firstProcess= firstProcess->getNextProcess();
    }
    if(firstProcess != nullptr)
    {
        process[i]=firstProcess;
        process[i]->setPcb(i);
        pcb[i]=1;
        if(firstProcess == reservedHead)
        reservedHead=reservedHead->getNextProcess();
        else
        {
            secondProcess->setNextProcess(firstProcess->getNextProcess());
        }
        if(firstProcess==reservedTail)
            reservedTail=secondProcess;
        return true;
    }
    return false;
}

void Widget::noAutoButtonClicked()
{
    autoCreate =0;
    noAutoButton.setStyleSheet(BUTTON_STYLE_3);
    oneTimeAutoButton.setStyleSheet(BUTTON_STYLE_2);
    twoTimeAutoButton.setStyleSheet(BUTTON_STYLE_2);
}

void Widget::oneTimeAutoButtonClicked()
{
    autoCreate =1;
    time1=2*ONE_SECOND;
    time1=startTimer(time1);
    noAutoButton.setStyleSheet(BUTTON_STYLE_2);
    oneTimeAutoButton.setStyleSheet(BUTTON_STYLE_3);
    twoTimeAutoButton.setStyleSheet(BUTTON_STYLE_2);
}

void Widget::twoTimeAutoButtonClicked()
{
    autoCreate =2;
    time1=1*ONE_SECOND;
    time1=startTimer(time1);
    noAutoButton.setStyleSheet(BUTTON_STYLE_2);
    oneTimeAutoButton.setStyleSheet(BUTTON_STYLE_2);
    twoTimeAutoButton.setStyleSheet(BUTTON_STYLE_3);
}

void Widget::createButtonClicked()
{
    createNewProcessByUser();
    createTimeInput.clear();
    createPriorityInput.clear();
    createMemoryInput.clear();
}

void Widget::resetButtonClicked()
{

    createTimeInput.clear();
    createPriorityInput.clear();
    createMemoryInput.clear();
}

void Widget::waitingShow1Clicked()
{
    int num=waitingShowOfPCB[0];
    if(pcb[num]==3)
    {
        pcb[num]=4;
        waitingShow[0].setStyleSheet(BUTTON_STYLE_5);
    }
    else
    {
        pcb[num]=3;
        waitingShow[0].setStyleSheet(BUTTON_STYLE_4);
    }

}

void Widget::waitingShow2Clicked()
{
    int num=waitingShowOfPCB[1];
    if(pcb[num]==3)
    {
        pcb[num]=4;
        waitingShow[1].setStyleSheet(BUTTON_STYLE_5);
    }
    else
    {
        pcb[num]=3;
        waitingShow[1].setStyleSheet(BUTTON_STYLE_4);
    }
}

void Widget::waitingShow3Clicked()
{
    int num=waitingShowOfPCB[2];
    if(pcb[num]==3)
    {
        pcb[num]=4;
        waitingShow[2].setStyleSheet(BUTTON_STYLE_5);
    }
    else
    {
        pcb[num]=3;
        waitingShow[2].setStyleSheet(BUTTON_STYLE_4);
    }
}

void Widget::waitingShow4Clicked()
{
    int num=waitingShowOfPCB[3];
    if(pcb[num]==3)
    {
        pcb[num]=4;
        waitingShow[3].setStyleSheet(BUTTON_STYLE_5);
    }
    else
    {
        pcb[num]=3;
        waitingShow[3].setStyleSheet(BUTTON_STYLE_4);
    }
}

void Widget::waitingShow5Clicked()
{
    int num=waitingShowOfPCB[4];
    if(pcb[num]==3)
    {
        pcb[num]=4;
        waitingShow[4].setStyleSheet(BUTTON_STYLE_5);
    }
    else
    {
        pcb[num]=3;
        waitingShow[4].setStyleSheet(BUTTON_STYLE_4);
    }
}

void Widget::waitingShow6Clicked()
{
    int num=waitingShowOfPCB[5];
    if(pcb[num]==3)
    {
        pcb[num]=4;
        waitingShow[5].setStyleSheet(BUTTON_STYLE_5);
    }
    else
    {
        pcb[num]=3;
        waitingShow[5].setStyleSheet(BUTTON_STYLE_4);
    }
}

