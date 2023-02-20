package com.company;

import static com.company.enums.RectangleEdge.*;
import static com.company.enums.TurnDirection.*;

public class Main {

    public static void main(String[] args) {
        // Testcase 1
        {
            Rectangle rect = new Rectangle(30, 30, 10, 20);

            System.out.println("Origin Rectangle:");
            rect.printRectangleInfo();

            System.out.println("Turn 90° CounterClockWise...\n");
            rect.turn(UpperLeft, CounterClockWise);

            System.out.println("Turned Rectangle:");
            rect.printRectangleInfo();
        }

        System.out.println("-----------------------------------------------------------------------------------------------");

        // Testcase 2
        {
            Rectangle rect = new Rectangle(new Point(30, 10), 10, 20);

            System.out.println("Origin Rectangle:");
            rect.printRectangleInfo();

            System.out.println("Turn 90° CounterClockWise...\n");
            rect.turn(BottomRight, ClockWise);

            System.out.println("Turned Rectangle:");
            rect.printRectangleInfo();
        }

        System.out.println("-----------------------------------------------------------------------------------------------");

        // Testcase 3
        {
            Rectangle rect = new Rectangle(new Point(30, 30), 20, 20);

            System.out.println("Origin Rectangle:");
            rect.printRectangleInfo();

            System.out.println("move rect...\n");
            rect.getPosition().moveBy(10,10);

            System.out.println("moved Rectangle:");
            rect.printRectangleInfo();
        }

        System.out.println("-----------------------------------------------------------------------------------------------");

        // Testcase 4
        {
            Rectangle rect = new Rectangle(new Point(30, 30), 10, 20);

            System.out.println("Origin Rectangle:");
            rect.printRectangleInfo();

            System.out.println("moving rect...\n");
            rect.getPosition().moveBy(10,10);

            System.out.println("moved Rectangle:");
            rect.printRectangleInfo();

            System.out.println("zooming in...");
            rect.zoom(4);

            System.out.println("zoomed Rectangle:");
            rect.printRectangleInfo();

            System.out.println("dividing Rectangles...");
            Rectangle[] rectangles = rect.getDividedRectangles();

            System.out.println("divided Rectangle:");
            rectangles[0].printRectangleInfo();
        }

        System.out.println("-----------------------------------------------------------------------------------------------");

        // Testcase 5
        {
            Rectangle rect = new Rectangle(new Point(30, 30), 20, 40);
            Rectangle secondRect = new Rectangle(new Point(40, 50), 10, 20);

            System.out.println("Origin Rectangle 1:");
            rect.printRectangleInfo();

            System.out.println("Origin Rectangle 2:");
            secondRect.printRectangleInfo();

            System.out.println("getIntersectedRect...");
            Rectangle interRect = rect.getIntersectedRect(secondRect);

            System.out.println("IntersectedRect:");
            if (interRect != null) {
                interRect.printRectangleInfo();
            } else {
                System.out.println("no intersected rectangle.");
            }
        }
    }
}
