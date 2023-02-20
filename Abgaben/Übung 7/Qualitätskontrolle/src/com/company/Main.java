package com.company;

public class Main {
    public static void main(String[] args) {
        // Testcase 1
        {
            char[][] cheese = {
                    "              ".toCharArray(),
                    "   **         ".toCharArray(),
                    "  *  *     *  ".toCharArray(),
                    "  ***  *  * * ".toCharArray(),
                    "      * *  *  ".toCharArray(),
                    "   *   *      ".toCharArray(),
                    "              ".toCharArray()
            };

            CheeseQualityControl.findHoles(cheese);
        }

        System.out.println("-----------------------------------------------------------------------------------------------");

        // Testcase 2
        {
            CheeseQualityControl.findHoles(null);
        }

        System.out.println("-----------------------------------------------------------------------------------------------");

        // Testcase 3
        {
            char[][] cheese = {
                    "              ".toCharArray(),
                    "           *  ".toCharArray(),
                    "              ".toCharArray(),
                    "     *        ".toCharArray(),
                    "              ".toCharArray(),
                    "   *         *".toCharArray(),
                    "              ".toCharArray()
            };

            CheeseQualityControl.findHoles(cheese);
        }

        System.out.println("-----------------------------------------------------------------------------------------------");

        // Testcase 4
        {
            char[][] cheese = {
                    "              ".toCharArray(),
                    "              ".toCharArray(),
                    "              ".toCharArray(),
                    "              ".toCharArray(),
                    "              ".toCharArray(),
                    "              ".toCharArray(),
                    "              ".toCharArray()
            };

            CheeseQualityControl.findHoles(cheese);
        }

        System.out.println("-----------------------------------------------------------------------------------------------");

        // Testcase 5
        {
            char[][] cheese = {
                    "**************".toCharArray(),
                    "**************".toCharArray(),
                    "**************".toCharArray(),
                    "**************".toCharArray(),
                    "**************".toCharArray(),
                    "**************".toCharArray(),
                    "**************".toCharArray()
            };

            CheeseQualityControl.findHoles(cheese);
        }

        System.out.println("-----------------------------------------------------------------------------------------------");
    }
}
