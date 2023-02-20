package com.company;

/**
 * The CheeseQualityControl class provides some
 * methods to check the quality of a cheese.
 *
 * @author Prescher Marco
 */
public class CheeseQualityControl {
    public static void findHoles(char[][] cheese) {
        int maxHoleSize = 0;
        int holeCnt = 0;

        if (cheese != null) {
            int col = 0;
            int row = 0;

            int currHoleSize;
            while (row < cheese.length - 1) {
                while (col < cheese[row].length - 1 && cheese[row][col] != '*') {
                    col++;
                }

                if (cheese[row][col] == '*') {
                    currHoleSize = CheeseQualityControl.getHoleSize(cheese, col, row);
                    if (currHoleSize != 0) {
                        if (maxHoleSize < currHoleSize) {
                            maxHoleSize = currHoleSize;
                        }

                        holeCnt++;
                    }
                }


                col = 0;
                row++;
            }
        }

        System.out.println("Nr. of holes:\t" + holeCnt);
        System.out.println("Biggest hole:\t" + maxHoleSize);
    }

    public static int getHoleSize(char[][] cheese, int col, int row) {
        int holeCnt = 0;

        if (cheese != null) {
            int initCol = col;
            int initRow = row;

            while (col < cheese[row].length - 1 && row < cheese.length - 1) {
                if (cheese[row][col + 1] == '*') {
                    cheese[row][col + 1] = '#';
                    col++;
                    holeCnt++;
                } else if (cheese[row + 1][col + 1] == '*') {
                    cheese[row + 1][col + 1] = '#';
                    col++;
                    row++;
                    holeCnt++;
                } else if (cheese[row + 1][col] == '*') {
                    cheese[row + 1][col] = '#';
                    row++;
                    holeCnt++;
                } else if (col > 0 && cheese[row + 1][col - 1] == '*') {
                    cheese[row + 1][col - 1] = '#';
                    col--;
                    row++;
                    holeCnt++;
                } else if (col > 0 && cheese[row][col - 1] == '*') {
                    cheese[row][col - 1] = '#';
                    col--;
                    holeCnt++;
                } else if (col > 0 && row > 0 && cheese[row - 1][col - 1] == '*') {
                    cheese[row - 1][col - 1] = '#';
                    col--;
                    row--;
                    holeCnt++;
                } else if (row > 0 && cheese[row - 1][col] == '*') {
                    cheese[row - 1][col] = '#';
                    row--;
                    holeCnt++;
                } else if (row > 0 && cheese[row - 1][col + 1] == '*') {
                    cheese[row - 1][col + 1] = '#';
                    col++;
                    row--;
                    holeCnt++;
                } else {
                    if (initCol == col && initRow == row) {
                        holeCnt++;
                    } else {
                        holeCnt = 0;
                    }

                    break;
                }

                if (initCol == col && initRow == row) {
                    break;
                }
            }
        }

        return holeCnt;
    }
}
