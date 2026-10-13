#include "ScreenRegionSelector.h"

#include <QGuiApplication>
#include <QScreen>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>

ScreenRegionSelector::ScreenRegionSelector(QWidget* parent) :
    QWidget(parent, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setCursor(Qt::CrossCursor);
    setMouseTracking(true);
    // 覆盖主屏幕
    if (QScreen* screen = QGuiApplication::primaryScreen())
    {
        setGeometry(screen->geometry());
    }
}

void ScreenRegionSelector::setExistingRegion(const QRect& region)
{
    m_existing = region;
}

void ScreenRegionSelector::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    // 全屏半透明遮罩
    painter.fillRect(rect(), QColor(0, 0, 0, 130));

    QRect sel = m_selecting ? m_current : m_existing;
    if (sel.isValid() && sel.width() > 1 && sel.height() > 1)
    {
        // 挖空选中区域，露出屏幕真实画面
        painter.setCompositionMode(QPainter::CompositionMode_Clear);
        painter.fillRect(sel, Qt::transparent);
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);

        // 高亮边框
        painter.setPen(QPen(QColor(0, 170, 255), 2));
        painter.drawRect(sel);

        // 尺寸提示
        const QString tip = QString("%1 × %2").arg(sel.width()).arg(sel.height());
        QFont font = painter.font();
        font.setPointSize(11);
        font.setBold(true);
        painter.setFont(font);
        QRect labelRect(sel.x(), sel.y(), 140, 26);
        if (labelRect.y() < 0)
            labelRect.moveTop(0);
        painter.fillRect(labelRect, QColor(0, 170, 255));
        painter.setPen(Qt::white);
        painter.drawText(labelRect, Qt::AlignCenter, tip);
    }
}

void ScreenRegionSelector::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_origin = event->pos();
        m_current = QRect(m_origin, m_origin);
        m_selecting = true;
        update();
    }
}

void ScreenRegionSelector::mouseMoveEvent(QMouseEvent* event)
{
    if (m_selecting)
    {
        m_current = QRect(m_origin, event->pos()).normalized();
        update();
    }
}

void ScreenRegionSelector::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && m_selecting)
    {
        m_selecting = false;
        QRect sel = QRect(m_origin, event->pos()).normalized();
        if (sel.width() < 6 || sel.height() < 6)
        {
            emit selectionCanceled();
        }
        else
        {
            emit regionSelected(sel);
        }
    }
}

void ScreenRegionSelector::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape)
    {
        emit selectionCanceled();
    }
    else
    {
        QWidget::keyPressEvent(event);
    }
}
