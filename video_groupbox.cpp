#include "video_groupbox.hpp"

VideoGroupBox::VideoGroupBox() {
    setTitle("Video");
    loadOrgButton = new QPushButton("Load Original");
    QObject::connect(loadOrgButton, &QPushButton::clicked, this, &VideoGroupBox::loadOriginal);
    
    loadResButton = new QPushButton("Load Result");
    QObject::connect(loadOrgButton, &QPushButton::clicked, this, &VideoGroupBox::loadResult);
    
    playButton = new QToolButton();
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    QObject::connect(playButton, &QToolButton::clicked, this, &VideoGroupBox::playClicked);
    
    browseButton = new QPushButton("Browse");
    QObject::connect(browseButton, &QPushButton::clicked, this, &VideoGroupBox::browse);
    
    volumeSlider = new QSlider(Qt::Horizontal);
    volumeSlider->setRange(0, 100);
    QObject::connect(volumeSlider, &QSlider::valueChanged, this, &VideoGroupBox::setVolume);
    
    trackSlider = new QSlider(Qt::Horizontal);
    //trackSlider->setEnabled(false);
    QObject::connect(trackSlider, &QSlider::valueChanged, this, &VideoGroupBox::setPosition);
    
    fileCombobox = new QComboBox();
    fileCombobox->setEditable(true);
    fileCombobox->setFrame(true);
    
    auto *layout = new QGridLayout();
    layout->addWidget(trackSlider, 0, 0, 1, 16);
    
    layout->addWidget(new QLabel("Start/Stop:"), 1, 0);
    layout->addWidget(playButton, 1, 1);
    layout->addWidget(loadOrgButton, 1, 14, 1, 2);
    
    layout->addWidget(new QLabel("Volume:"), 2, 0);
    layout->addWidget(volumeSlider, 2, 1);
    layout->addWidget(loadResButton, 2, 14, 1, 2);
    
    layout->addWidget(new QLabel("File Location:"), 3, 0);
    layout->addWidget(fileCombobox, 3, 1, 1, 14);
    layout->addWidget(browseButton, 3, 15);
    setLayout(layout);
}

void VideoGroupBox::setVolume(int volume) {
    emit changeVolume(volume);
}

void VideoGroupBox::setPosition(int position){
    emit changePosition(position);
}

void VideoGroupBox::playClicked() {
    emit play();
}

void VideoGroupBox::browse() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath());
    if (!fileName.isEmpty()) {
        if (fileCombobox->findText(fileName) == -1)
            fileCombobox->addItem(fileName);
        fileCombobox->setCurrentIndex(fileCombobox->findText(fileName));
    }
}

void VideoGroupBox::loadOriginal() {
    QString file = fileCombobox->currentText();
    emit changeFile(file);
}

void VideoGroupBox::loadResult() {
    QString file = fileCombobox->currentText();
    emit changeFile(file);
}
