#include "util.h"

#include <QWidget>
#include <QHeaderView>
#include <QTableWidget>
#include <QUuid>
#include <QFile>

#include "qmath.h"
#include "global.h"
#include "mainwindow.h"

#define TABLE_ROW_HEIGHT  30      //表格高度

void Util::setWidgetColor(QWidget *widget, QColor &color)
{
    widget->setStyleSheet("background-color:rgba("+QString::number(color.red())\
                          +","+QString::number(color.green())\
                          +","+QString::number(color.blue())\
                          +","+QString::number(color.alpha())+")");
}

//获取字体的信息
QString Util::getFontInfo(QFont font)
{
    return QString("%1px,%2").arg(font.pointSize()).arg(font.family());
}

//决定每个控件的纵向深度，在添加或复制时候自动调用
qreal Util::getGlobalZValue()
{
    GlobalItemZValue += 0.1;
    return GlobalItemZValue;
}

//在清空控件时自动清0
void Util::resetGlobalZValue()
{
    GlobalItemZValue = 0;
}

//获取唯一标识符
QString Util::getUUID()
{
    return QUuid::createUuid().toString();
}

qreal Util::getMaxNum(qreal &a, qreal &b)
{
    if(a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
    return 0;
}

//设置表头的样式
void Util::setTableStylesheet(QTableWidget *table)
{
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setFocusPolicy(Qt::NoFocus);
    table->setStyleSheet("selection-color:white;selection-background-color:#567dbc");//
//    table->horizontalHeader()->setStyleSheet("QHeaderView::section{color:white;border:none;border-radius:5px;height:23px;margin-left:1px; \
//                                                     background-color:#567dbc;}");
    table->horizontalHeader()->setVisible(true);
}

//创建表格单元格,并且设置各行变色
void Util::createTableItem(const int rowCount, QTableWidget *table)
{
    for(int i=0 ; i<rowCount ; i++)
    {
        int row = table->rowCount();
        table->setRowCount(row+1);
        table->setRowHeight(row,TABLE_ROW_HEIGHT);

        for(int j = 0 ; j < table->columnCount(); j++)
        {
            QTableWidgetItem * item = new QTableWidgetItem();
            item->setTextColor(Qt::black);
            item->setTextAlignment(Qt::AlignCenter);

            if(row%2==0)
            {
                item->setBackgroundColor(QColor(100,100,100,15));
            }
            table->setItem(i,j,item);
        }
    }
}

//删除表格中所有的单元格(除表头)
void Util::removeTableItem(QTableWidget *table)
{
    int rowCount = table->rowCount();

    for(int i = rowCount-1; i >= 0; i--)
    {
         table->removeRow(i);
    }
}

//清除表格的内容(除表头)
void Util::clearTableData(QTableWidget *table)
{
    int rowCount = table->rowCount();
    int columnCount = table->columnCount();
    for(int i = 0 ; i <rowCount ; i++ )
    {
        for(int j = 0 ; j < columnCount;  j++)
        {
            table->item(i,j)->setText("");
        }
    }
}

//将弧度转换为角度
qreal Util::radinToAngle(const qreal &radin)
{
     return 180/M_PI*radin;
}

//根据不同类型加载对应的图片
void Util::loadPixmapByGType(GraphicsType type, QPixmap &pixmap)
{
    switch(type)
    {
        case GRA_SQUARE:
                           pixmap.load(":/images/square.png");
                           break;
        case GRA_RECT:
                           pixmap.load(":/images/rectange.png");
                           break;
        case GRA_ROUND_RECT:
                           pixmap.load(":/images/roundedrect.png");
                           break;
        case GRA_CIRCLE:
                           pixmap.load(":/images/circle.png");
                           break;
        case GRA_ELLIPSE:
                           pixmap.load(":/images/ellipse.png");
                           break;
        case GRA_POLYGON:
                           pixmap.load(":/images/diamonds.png");
                           break;
        case GRA_TEXT:
                           pixmap.load(":/images/text.png");
                           break;
        case GRA_NODE_PORT:
                           pixmap.load(":/images/nodePort.png");
                           break;
        case GRA_NODE_TRIANGLE_OUT:
                           pixmap.load(":/images/nodeTriangle.png");
                           break;
        case GRA_NODE_TRIANGLE_IN:
                           pixmap.load(":/images/nodeTriangle.png");
                           break;
        case GRA_NODE_HALF_CIRCLE_IN:
                           pixmap.load(":/images/nodeHalfCircleIn.png");
                           break;
        case GRA_NODE_HALF_CIRCLE_OUT:
                           pixmap.load(":/images/nodeHalfCircleOut.png");
                           break;
        case GRA_NODE_CIRCLE:
                           pixmap.load(":/images/circle.png");
                           break;
        case GRA_PARALLELOGRAM:
                           pixmap.load(":/images/parallelogram.png");
                           break;
        case GRA_LOOP_UP:
                           pixmap.load(":/images/loop_up.png");
                           break;
        case GRA_LOOP_DOWN:
                           pixmap.load(":/images/loop_down.png");
                           break;
        case GRA_ANNOTATION:
                           pixmap.load(":/images/annotation.png");
                           break;
        case GAR_PARALLE:
                           pixmap.load(":/images/parallel.png");
                           break;
#ifdef ADD_STATE_MODEL
        //状态机
        case GRA_STATE_START:
                           pixmap.load(":/images/State_Start.png");
                           break;
        case GRA_STATE_END:
                           pixmap.load(":/images/State_End.png");
                           break;
        case GRA_STATE_PROCESS:
                           pixmap.load(":/images/roundedrect.png");
                           break;
        //遮罩
        case GRA_MASK_RECT:
                           pixmap.load(":/images/rectange.png");
                           break;

        case GRA_MASK_BOUND_RECT:
                           pixmap.load(":/images/roundedrect.png");
                           break;
        case GRA_MASK_CIRCLE:
                           pixmap.load(":/images/circle.png");
                           break;
        case GRA_NODE_PROCESS:
                           pixmap.load(":/images/rectange.png");
                           break;
#endif
        default:
                           break;
    }
}

//只显示提示信息，无需获取返回值
void Util::showWarn(QString tipText)
{
    QMessageBox::warning(GlobalMainWindow,"警告",tipText,QMessageBox::Yes,QMessageBox::Yes);
}

//全局显示警告信息
int Util::getWarnChoice(QString tipText,QMessageBox::StandardButton butt)
{
    int result = QMessageBox::warning(GlobalMainWindow,"警告",tipText,QMessageBox::Yes|butt,butt);

    return result;
}

//只显示提示信息，无需获取返回值
void Util::showInfo(QString tipText)
{
    QMessageBox::information(GlobalMainWindow,"提示",tipText,QMessageBox::Yes,QMessageBox::Yes);
}

//全局显示信息提示信息
QMessageBox::StandardButton Util::getInfoChoice(QString tipText,QMessageBox::StandardButton butt)
{
    return QMessageBox::information(GlobalMainWindow,"提示",tipText,QMessageBox::Yes|butt,butt);
}

//是否是合法的文件，在本地打开和拖入时使用
ReturnType Util::isIllegalFile(QDataStream & stream)
{
    int softVersion;
    stream >>softVersion;
    if(softVersion != M_VERTION)
    {
        return FILE_VERSION;
    }

    QString fileFlag;
    stream>>fileFlag;

    if(fileFlag != SaveFileHeadFlag)
    {
        return FILE_ILLEGAL;
    }

    return RETURN_SUCCESS;
}
