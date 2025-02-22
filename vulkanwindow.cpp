#include "vulkanwindow.h"
#include <QPainter>
#include <QVulkanFunctions>

VulkanWindow::VulkanWindow(QWidget *parent) : QWidget(parent) {
    setMinimumSize(800, 600);

    // Создаём Vulkan-инстанс
    if (!vulkanInstance.create()) {
        qFatal("Не удалось создать Vulkan-инстанс");
    }

    // Проверяем, что инстанс валиден (замена supportsVulkan)
    if (!vulkanInstance.isValid()) {
        qFatal("Vulkan не поддерживается!");
    }

    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_NativeWindow);
}

VulkanWindow::~VulkanWindow() {
    // Очистка ресурсов (если нужно)
}

void VulkanWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::black);
    painter.setPen(Qt::white);
    painter.drawText(rect(), Qt::AlignCenter, "Vulkan Rendering...");
}
