#ifndef CENTEREDITEMDELEGATE_H
#define CENTEREDITEMDELEGATE_H

#include <QItemDelegate>
#include <QTableView>
#include <QSqlTableModel>

// 自定义 QItemDelegate 用于设置居中对齐
class CenteredItemDelegate : public QItemDelegate {
public:
    CenteredItemDelegate(QObject *parent = nullptr) : QItemDelegate(parent) {}

    // 重写 createEditor 函数
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override {
        QWidget* editor = QItemDelegate::createEditor(parent, option, index);
        return editor;
    }

    // 重写 paint 函数
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QStyleOptionViewItem newOption(option);
        newOption.displayAlignment = Qt::AlignCenter;  // 设置文本居中对齐
        QItemDelegate::paint(painter, newOption, index); // 使用原有的绘制逻辑
    }
};

#endif // CENTEREDITEMDELEGATE_H
