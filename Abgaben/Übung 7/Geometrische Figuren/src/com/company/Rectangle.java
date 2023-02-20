package com.company;

import com.company.enums.RectangleEdge;
import com.company.enums.TurnDirection;

/**
 * The Rectangle class provides a Rectangle and different geometric
 * methods to manipulate the object.
 *
 * @author Prescher Marco
 */
public class Rectangle {
    private Point pos;
    private int width;
    private int height;

    public Rectangle(Point pos, int width, int height) {
        this.pos = pos;
        this.width = width;
        this.height = height;
    }

    public Rectangle(int x, int y, int width, int height) {
        this.pos = new Point(x, y);
        this.width = width;
        this.height = height;
    }

    public Point getPosition() {
        return this.pos;
    }

    public int getWidth() {
        return this.width;
    }

    public int getHeight() {
        return this.height;
    }

    public void turn(RectangleEdge turningEdge, TurnDirection direction) {
        int posX = this.pos.getX();
        int posY = this.pos.getY();

        switch (turningEdge) {
            case UpperLeft:
                if (direction == TurnDirection.CounterClockWise) {
                    this.pos = new Point(posX, posY - this.width);
                } else {
                    this.pos = new Point(posX - this.height, posY);
                }

                break;

            case UpperRight:
                if (direction == TurnDirection.CounterClockWise) {
                    this.pos = new Point(posX + this.width, posY);
                } else {
                    this.pos = new Point(posX + (this.width - this.height), posY - this.width);
                }

                break;

            case BottomLeft:
                if (direction == TurnDirection.CounterClockWise) {
                    this.pos = new Point(posX - this.height, posY + this.width);
                } else {
                    this.pos = new Point(posX, posY + this.height);
                }

                break;

            case BottomRight:
                if (direction == TurnDirection.CounterClockWise) {
                    this.pos = new Point(posX + (this.width - this.height), posY - this.height);
                } else {
                    this.pos = new Point(posX + this.width, posY + (this.height - this.width));
                }

                break;
        }

        int temp = this.height;

        //noinspection SuspiciousNameCombination
        this.height = this.width;
        this.width = temp;
    }

    public boolean isSquare() {
        return this.width == this.height;
    }

    public int getPerimeter() {
        return 2 * (this.width + this.height);
    }

    public int getCircleRadius() {
        return (int) (0.5 * Math.sqrt(Math.pow(this.width, 2) + Math.pow(this.height, 2)));
    }

    public int getCircumference() {
        return (int) (2 * Math.PI * this.getCircleRadius());
    }

    public void zoom(int factor) {
        if (factor > 0) {
            int zoomWidth = this.width * factor;
            int zoomHeight = this.height * factor;

            this.pos.setX(this.pos.getX() - ((zoomWidth - this.width) / 2));
            this.pos.setY(this.pos.getY() - ((zoomHeight - this.height) / 2));

            this.width = zoomWidth;
            this.height = zoomHeight;
        }
    }

    public Rectangle[] getDividedRectangles() {
        int posX = this.pos.getX();
        int posY = this.pos.getY();

        int halfWidth = this.width / 2;
        int halfHeight = this.height / 2;

        return new Rectangle[]{
                new Rectangle(new Point(posX, posY), halfWidth, halfHeight),
                new Rectangle(new Point(posX, posY + halfHeight), halfWidth, halfHeight),
                new Rectangle(new Point(posX + halfWidth, posY + halfHeight), halfWidth, halfHeight),
                new Rectangle(new Point(posX + halfWidth, posY), halfWidth, halfHeight)
        };
    }

    public Rectangle getIntersectedRect(Rectangle secondRectangle) {
        int posX = this.pos.getX();
        int posY = this.pos.getY();

        int secondRectPosX = secondRectangle.getPosition().getX();
        int secondRectPosY = secondRectangle.getPosition().getY();

        int interceptX = Math.max(posX, secondRectPosX);
        int interceptY = Math.max(posY, secondRectPosY);

        int iUpperRightX = Math.min(posX + this.width, secondRectPosX + secondRectangle.getWidth());
        int iBottomLeftY = Math.min(posY + this.height, secondRectPosY + secondRectangle.getHeight());

        Rectangle intersectedRect = null;
        if (iUpperRightX > interceptX && iBottomLeftY > interceptY) {
            intersectedRect = new Rectangle(new Point(interceptX, interceptY), iUpperRightX - interceptX, iBottomLeftY - interceptY);
        }

        return intersectedRect;
    }

    public void printRectangleInfo() {
        System.out.println("xPos:\t" + this.pos.getX() + "\tyPos:\t" + this.pos.getY() + "\n" +
                "width:\t" + this.width + "\theight:\t" + this.height + "\n\n" +
                "isSq:\t" + this.isSquare() + "\tperimeter:\t" + this.getPerimeter() + "\n" +
                "radius:\t" + this.getCircleRadius() + "\t\tcircumference:\t" + this.getCircumference() + "\n"
        );
    }
}