#include "log_widget.hpp"
#include <string>
#include <iostream>

LogWidget::LogWidget(): QPlainTextEdit() {
    setReadOnly(true);
}

void LogWidget::write(QString content) {
    appendPlainText(content);
}

void LogWidget::clear() {
    QPlainTextEdit::clear();
}
