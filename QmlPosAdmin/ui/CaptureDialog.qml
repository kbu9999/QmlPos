import QtQuick 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.3
import QtMultimedia 5.0

import libPos 0.1

Dialog {
    id: captureDlg

    signal captured(var preview)

    contentItem: Column {

        VideoOutput {
            id: viewfinder
            width: 640; height: 480
            source: Camera {
                id: camera

                //imageCapture {onImageCaptured: captureDlg.captured(preview) }
            }
        }
        Row {
            Button {
                text: "Capturar";
                onClicked: {
                    camera.imageCapture.capture()
                    captureDlg.close();
                }
            }

            Button {
                text: "Close";
                onClicked: captureDlg.close()
            }
        }

    }

    onVisibleChanged: {
        if (visible) camera.start()
        else camera.stop()
    }

    ImageProcess {
        camera: camera
        onImageChanged: {
            console.log("capture")
            captureDlg.captured(image);
        }
    }
}

