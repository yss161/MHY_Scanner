#pragma once

#include <QWidget>
#include <QRect>
#include <QPoint>

// 全屏半透明框选窗口：用户拖拽选择屏幕检测范围（返回逻辑坐标）
class ScreenRegionSelector : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenRegionSelector(QWidget* parent = nullptr);
    void setExistingRegion(const QRect& region);

Q_SIGNALS:
    void regionSelected(const QRect& region);
    void selectionCanceled();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

private:
    QRect m_existing;
    QRect m_current;
    QPoint m_origin;
    bool m_selecting{ false };
};
