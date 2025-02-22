#ifndef VULKANWINDOW_H
#define VULKANWINDOW_H

#include <QWidget>
#include <QVulkanInstance>

class VulkanWindow : public QWidget {
    Q_OBJECT

public:
    explicit VulkanWindow(QWidget *parent = nullptr);
    ~VulkanWindow();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QVulkanInstance vulkanInstance;
};

#endif // VULKANWINDOW_H
