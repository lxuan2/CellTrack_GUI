#include "log_widget.hpp"

LogWidget::LogWidget(): QPlainTextEdit() {
    setReadOnly(true);
}

void LogWidget::write(QString content, bool warn) {
    
    appendPlainText(content + "\n");
}

void LogWidget::clear() {
    QPlainTextEdit::clear();
}
