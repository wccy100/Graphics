#include "serviceinputdelegate.h"

#include <QComboBox>
#include <QLineEdit>

ServiceInputDelegate::ServiceInputDelegate()
{
    stringList<<QString("bool")<<QString("char")<<QString("short")<<QString("int")<<QString("float")<<QString("double");
}

//���������Ŀؼ�
QWidget * ServiceInputDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column() == 1)
    {
        QComboBox * box = new QComboBox(parent);
        box->addItems(stringList);
        return box;
    }
    else
    {
        QLineEdit * edit = new QLineEdit(parent);
        return edit;
    }
    return NULL;
}

//���ô����ؼ���ֵ
void ServiceInputDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value = index.model()->data(index,Qt::DisplayRole).toString();
    if(index.column() == 1)
    {
        QComboBox * box = dynamic_cast<QComboBox *>(editor);
        if(box)
        {
            box->setCurrentIndex(stringList.indexOf(value));
        }
    }
    else
    {
        QLineEdit * edit = dynamic_cast<QLineEdit *>(editor);
        if(edit)
        {
            edit->setText(value);
        }
    }
}

//���´����ؼ���λ�óߴ�
void ServiceInputDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

//����ģ������
void ServiceInputDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QString value;
    if(index.column() == 1)
    {
        QComboBox * box = dynamic_cast<QComboBox *>(editor);
        if(box)
        {
            value = box->currentText();
        }
    }
    else
    {
        QLineEdit * edit = dynamic_cast<QLineEdit *>(editor);
        if(edit)
        {
            value = edit->text();
        }
    }
    model->setData(index,value,Qt::EditRole);
}