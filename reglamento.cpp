#include "reglamento.h"
#include "ui_reglamento.h"


REGLAMENTO::REGLAMENTO(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::REGLAMENTO)
{
    ui->setupUi(this);
}

REGLAMENTO::~REGLAMENTO()
{
    delete ui;
}

void REGLAMENTO::on_actionREGLAMENTO_triggered()
{
    // Obtener el recurso del archivo PDF desde el archivo .qrc
    QFile pdfFile(ARCHIVO);

    // Verificar si el archivo PDF se puede abrir correctamente
    if (!pdfFile.open(QIODevice::ReadOnly))
    {
        // Manejar el error, si es necesario
        // Por ejemplo, mostrar un mensaje de error
        return;
    }

    // Crear un archivo temporal para guardar el contenido del PDF
    QString tempFilePath = QDir::tempPath() + "/reglamento_temp.pdf";
    QFile tempFile(tempFilePath);
    if (!tempFile.open(QIODevice::WriteOnly))
    {
        // Manejar el error, si es necesario
        // Por ejemplo, mostrar un mensaje de error
        pdfFile.close();
        return;
    }

    // Leer el contenido del PDF desde el recurso y escribirlo en el archivo temporal
    tempFile.write(pdfFile.readAll());

    // Cerrar ambos archivos
    pdfFile.close();
    tempFile.close();

    // Abrir el archivo PDF usando el visor de PDF predeterminado del sistema
    QDesktopServices::openUrl(QUrl::fromLocalFile(tempFilePath));
}
