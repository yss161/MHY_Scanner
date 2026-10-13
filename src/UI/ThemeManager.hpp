#pragma once

#include <QApplication>
#include <QPalette>
#include <QStyleHints>

// 主题管理：浅色 / 深色两套现代扁平样式
namespace Theme
{

inline const char* lightStyleSheet()
{
    return R"(
* {
    font-family: "Microsoft YaHei", "微软雅黑", "Segoe UI";
    font-size: 13px;
}

QMainWindow, QDialog, QWidget#centralWidget {
    background: #eff1f5;
}

QWidget {
    color: #4c4f69;
}

QLabel {
    background: transparent;
    color: #4c4f69;
}

QLabel#previewLabel {
    background: #1e1e2e;
    color: #8c8fa1;
    border: 1px solid #ccd0da;
    border-radius: 8px;
}

QLineEdit {
    background: #ffffff;
    color: #4c4f69;
    border: 1px solid #ccd0da;
    border-radius: 6px;
    padding: 6px 10px;
    selection-background-color: #1e66f5;
    selection-color: #ffffff;
}
QLineEdit:focus { border: 1px solid #1e66f5; }
QLineEdit:disabled { background: #e6e9ef; color: #9ca0b0; }

QPushButton {
    background: #e6e9ef;
    color: #4c4f69;
    border: none;
    border-radius: 6px;
    padding: 8px 16px;
    font-weight: bold;
}
QPushButton:hover { background: #dce0e8; }
QPushButton:pressed { background: #ccd0da; }
QPushButton:checked { background: #1e66f5; color: #ffffff; }
QPushButton:disabled { background: #e6e9ef; color: #bcc0cc; }

QPushButton#pBtstartScreen, QPushButton#pBtStream {
    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #1e66f5, stop:1 #7287fd);
    color: #ffffff;
    border-radius: 8px;
    padding: 10px 18px;
}
QPushButton#pBtstartScreen:hover, QPushButton#pBtStream:hover {
    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #0f55e6, stop:1 #5f76f0);
}
QPushButton#pBtstartScreen:checked, QPushButton#pBtStream:checked {
    background: #dc8a78;
    color: #ffffff;
}

QPushButton#pBtSelectRegion {
    background: #ffffff;
    color: #1e66f5;
    border: 1px solid #1e66f5;
    border-radius: 8px;
    padding: 10px 18px;
}
QPushButton#pBtSelectRegion:hover { background: #eaf0ff; }

QTableWidget {
    background: #ffffff;
    alternate-background-color: #f5f6fa;
    border: 1px solid #ccd0da;
    border-radius: 8px;
    gridline-color: #e6e9ef;
    selection-background-color: #dce6ff;
    selection-color: #1e66f5;
}
QTableWidget::item {
    border: none;
    padding: 4px 6px;
}
QHeaderView::section {
    background: #e6e9ef;
    color: #4c4f69;
    border: none;
    border-bottom: 1px solid #ccd0da;
    border-right: 1px solid #ccd0da;
    padding: 6px 8px;
    font-weight: bold;
}

QComboBox {
    background: #ffffff;
    color: #4c4f69;
    border: 1px solid #ccd0da;
    border-radius: 6px;
    padding: 5px 10px;
}
QComboBox:focus { border: 1px solid #1e66f5; }
QComboBox::drop-down { border: none; width: 22px; }
QComboBox QAbstractItemView {
    background: #ffffff;
    color: #4c4f69;
    border: 1px solid #ccd0da;
    selection-background-color: #dce6ff;
    selection-color: #1e66f5;
}

QCheckBox { spacing: 6px; }
QCheckBox::indicator {
    width: 16px; height: 16px;
    border: 1px solid #bcc0cc;
    border-radius: 4px;
    background: #ffffff;
}
QCheckBox::indicator:checked {
    background: #1e66f5;
    border: 1px solid #1e66f5;
}

QMenuBar {
    background: #e6e9ef;
    color: #4c4f69;
    border-bottom: 1px solid #ccd0da;
}
QMenuBar::item:selected { background: #dce0e8; border-radius: 4px; }
QMenu {
    background: #ffffff;
    color: #4c4f69;
    border: 1px solid #ccd0da;
    border-radius: 8px;
    padding: 4px;
}
QMenu::item { padding: 6px 24px; border-radius: 4px; }
QMenu::item:selected { background: #dce6ff; color: #1e66f5; }

QTabWidget::pane { border: 1px solid #ccd0da; border-radius: 8px; }
QTabBar::tab {
    background: #e6e9ef;
    color: #6c6f85;
    padding: 8px 16px;
    border-top-left-radius: 6px;
    border-top-right-radius: 6px;
    margin-right: 2px;
}
QTabBar::tab:selected { background: #ffffff; color: #1e66f5; font-weight: bold; }

QGroupBox {
    background: #ffffff;
    border: 1px solid #ccd0da;
    border-radius: 8px;
    margin-top: 12px;
}
QGroupBox::title { subcontrol-origin: margin; left: 12px; padding: 0 4px; color: #1e66f5; }

QMessageBox { background: #eff1f5; }
QScrollBar:vertical { background: #e6e9ef; width: 10px; border-radius: 5px; }
QScrollBar::handle:vertical { background: #bcc0cc; border-radius: 5px; min-height: 24px; }
QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0; }
)";
}

inline const char* darkStyleSheet()
{
    return R"(
* {
    font-family: "Microsoft YaHei", "微软雅黑", "Segoe UI";
    font-size: 13px;
}

QMainWindow, QDialog, QWidget#centralWidget {
    background: #1e1e2e;
}

QWidget {
    color: #cdd6f4;
}

QLabel {
    background: transparent;
    color: #cdd6f4;
}

QLabel#previewLabel {
    background: #11111b;
    color: #6c7086;
    border: 1px solid #45475a;
    border-radius: 8px;
}

QLineEdit {
    background: #313244;
    color: #cdd6f4;
    border: 1px solid #45475a;
    border-radius: 6px;
    padding: 6px 10px;
    selection-background-color: #89b4fa;
    selection-color: #1e1e2e;
}
QLineEdit:focus { border: 1px solid #89b4fa; }
QLineEdit:disabled { background: #181825; color: #6c7086; }

QPushButton {
    background: #313244;
    color: #cdd6f4;
    border: none;
    border-radius: 6px;
    padding: 8px 16px;
    font-weight: bold;
}
QPushButton:hover { background: #45475a; }
QPushButton:pressed { background: #181825; }
QPushButton:checked { background: #89b4fa; color: #1e1e2e; }
QPushButton:disabled { background: #181825; color: #585b70; }

QPushButton#pBtstartScreen, QPushButton#pBtStream {
    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #89b4fa, stop:1 #b4befe);
    color: #1e1e2e;
    border-radius: 8px;
    padding: 10px 18px;
}
QPushButton#pBtstartScreen:hover, QPushButton#pBtStream:hover {
    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #7aa2f7, stop:1 #a5aef5);
}
QPushButton#pBtstartScreen:checked, QPushButton#pBtStream:checked {
    background: #f38ba8;
    color: #1e1e2e;
}

QPushButton#pBtSelectRegion {
    background: #313244;
    color: #89b4fa;
    border: 1px solid #89b4fa;
    border-radius: 8px;
    padding: 10px 18px;
}
QPushButton#pBtSelectRegion:hover { background: #45475a; }

QTableWidget {
    background: #181825;
    alternate-background-color: #1e1e2e;
    border: 1px solid #45475a;
    border-radius: 8px;
    gridline-color: #313244;
    selection-background-color: #313244;
    selection-color: #89b4fa;
}
QTableWidget::item {
    border: none;
    padding: 4px 6px;
}
QHeaderView::section {
    background: #313244;
    color: #cdd6f4;
    border: none;
    border-bottom: 1px solid #45475a;
    border-right: 1px solid #45475a;
    padding: 6px 8px;
    font-weight: bold;
}

QComboBox {
    background: #313244;
    color: #cdd6f4;
    border: 1px solid #45475a;
    border-radius: 6px;
    padding: 5px 10px;
}
QComboBox:focus { border: 1px solid #89b4fa; }
QComboBox::drop-down { border: none; width: 22px; }
QComboBox QAbstractItemView {
    background: #313244;
    color: #cdd6f4;
    border: 1px solid #45475a;
    selection-background-color: #89b4fa;
    selection-color: #1e1e2e;
}

QCheckBox { spacing: 6px; }
QCheckBox::indicator {
    width: 16px; height: 16px;
    border: 1px solid #585b70;
    border-radius: 4px;
    background: #313244;
}
QCheckBox::indicator:checked {
    background: #89b4fa;
    border: 1px solid #89b4fa;
}

QMenuBar {
    background: #313244;
    color: #cdd6f4;
    border-bottom: 1px solid #45475a;
}
QMenuBar::item:selected { background: #45475a; border-radius: 4px; }
QMenu {
    background: #313244;
    color: #cdd6f4;
    border: 1px solid #45475a;
    border-radius: 8px;
    padding: 4px;
}
QMenu::item { padding: 6px 24px; border-radius: 4px; }
QMenu::item:selected { background: #89b4fa; color: #1e1e2e; }

QTabWidget::pane { border: 1px solid #45475a; border-radius: 8px; }
QTabBar::tab {
    background: #313244;
    color: #a6adc8;
    padding: 8px 16px;
    border-top-left-radius: 6px;
    border-top-right-radius: 6px;
    margin-right: 2px;
}
QTabBar::tab:selected { background: #1e1e2e; color: #89b4fa; font-weight: bold; }

QGroupBox {
    background: #181825;
    border: 1px solid #45475a;
    border-radius: 8px;
    margin-top: 12px;
}
QGroupBox::title { subcontrol-origin: margin; left: 12px; padding: 0 4px; color: #89b4fa; }

QMessageBox { background: #1e1e2e; }
QScrollBar:vertical { background: #313244; width: 10px; border-radius: 5px; }
QScrollBar::handle:vertical { background: #585b70; border-radius: 5px; min-height: 24px; }
QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0; }
)";
}

inline void apply(QApplication& app, bool dark)
{
    app.setStyleSheet(dark ? darkStyleSheet() : lightStyleSheet());
    app.styleHints()->setColorScheme(dark ? Qt::ColorScheme::Dark : Qt::ColorScheme::Light);

    QPalette pal = app.palette();
    if (dark)
    {
        pal.setColor(QPalette::Window, QColor("#1e1e2e"));
        pal.setColor(QPalette::WindowText, QColor("#cdd6f4"));
        pal.setColor(QPalette::Base, QColor("#181825"));
        pal.setColor(QPalette::AlternateBase, QColor("#1e1e2e"));
        pal.setColor(QPalette::Text, QColor("#cdd6f4"));
        pal.setColor(QPalette::Button, QColor("#313244"));
        pal.setColor(QPalette::ButtonText, QColor("#cdd6f4"));
        pal.setColor(QPalette::Highlight, QColor("#89b4fa"));
        pal.setColor(QPalette::HighlightedText, QColor("#1e1e2e"));
        pal.setColor(QPalette::ToolTipBase, QColor("#313244"));
        pal.setColor(QPalette::ToolTipText, QColor("#cdd6f4"));
        pal.setColor(QPalette::PlaceholderText, QColor("#6c7086"));
    }
    else
    {
        pal = app.style()->standardPalette();
        pal.setColor(QPalette::PlaceholderText, QColor("#9ca0b0"));
    }
    app.setPalette(pal);
}

}
