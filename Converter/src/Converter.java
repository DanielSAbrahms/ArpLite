import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Converter {
    public static void main(String[] args) throws IOException {
        String fName = "Test.csv";
        String thisLine;
        FileInputStream fis = null;
        try {
            fis = new FileInputStream(fName);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        DataInputStream myInput = new DataInputStream(fis);
        List<String[]> lines = new ArrayList<String[]>();
        while ((thisLine = myInput.readLine()) != null) {
            lines.add(thisLine.split(","));
        }


// convert our list to a String array.
        String[][] array = new String[lines.size()][0];
        lines.toArray(array);



        System.out.println("{");
        for (int i = 0; i < array.length; i++) {
            System.out.print("{");
            for (int j = 0; j < 9; j++) {
                if (j != 8) System.out.print("B" + array[i][j+4] + ", ");
                else System.out.print(array[i][j+4]);
            }
            System.out.println("},");
        }
        System.out.println("};");
    }
}
