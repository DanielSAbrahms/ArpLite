import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.layout.GridPane;
import javafx.scene.shape.Circle;

import java.awt.*;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class Controller implements Initializable {

    private FXMLLoader loader;

    private @FXML GridPane mainGrid;
    private @FXML Circle a00, a01, a02, a03, a04, a05, a06, a07,
            a10, a11, a12, a13, a14, a15, a16, a17,
            a20, a21, a22, a23, a24, a25, a26, a27,
            a30, a31, a32, a33, a34, a35, a36, a37,
            a40, a41, a42, a43, a44, a45, a46, a47,
            a50, a51, a52, a53, a54, a55, a56, a57,
            a60, a61, a62, a63, a64, a65, a66, a67,
            a70, a71, a72, a73, a74, a75, a76, a77;

    private Circle[][] circles;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        Converter converter = new Converter();
        String[][] byteArray = {{}};
        try {
            byteArray = converter.convert("Test.csv");
        } catch (IOException e) {
            e.printStackTrace();
        }
        circles = new Circle[][]{
                {a00, a01, a02, a03, a04, a05, a06, a07},
                {a10, a11, a12, a13, a14, a15, a16, a17},
                {a20, a21, a22, a23, a24, a25, a26, a27},
                {a30, a31, a32, a33, a34, a35, a36, a37},
                {a40, a41, a42, a43, a44, a45, a46, a47},
                {a50, a51, a52, a53, a54, a55, a56, a57},
                {a60, a61, a62, a63, a64, a65, a66, a67},
                {a70, a71, a72, a73, a74, a75, a76, a77}
        };
        /*
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j <=4; ++j) {
                Circle temp1 = circles[i][j];
                circles[i][j] = circles[8-i-1][8-j-1];
                circles[8-i-1][8-j-1] = temp1;
                Circle temp2 = circles[8-j-1][i];
                circles[8-j-1][i] = circles[j][8-i-1];
                circles[j][8-i-1] = temp2;
            }
        }
        */
        switchAll(false);
        update(byteArray, 1);


    }


    private void switchOne(int i, int j, boolean turnOn) {
        circles[i][j].setVisible(turnOn);
    }
    private void switchAll (boolean turnOn) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                switchOne(i, j, turnOn);
            }
        }
    }

    private void update (String[][] a, int beat) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (a[beat-1][i+4].equals("")) break;
                if (a[beat-1][i+4].charAt(j)==('1')) switchOne(i, j, true);
            }
        }
    }


}
