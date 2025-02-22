#include <QApplication>
#include "vulkanwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    VulkanWindow vulkanWindow;
    vulkanWindow.show();

    return app.exec();
}
