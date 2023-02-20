package com.company;

import com.company.enums.Direction;
import com.company.enums.FieldType;

public class Main {

    public static void main(String[] args) {
        DistributionCenter distCenter = new DistributionCenter(2, 2, 200, 200);
        distCenter.setTypeToField(0, 0, FieldType.LOADING_STATION);
        distCenter.setTypeToField(1, 1, FieldType.UNLOADING_STATION);
        distCenter.setTypeToField(1, 0, FieldType.OBSTACLE);

        Trolley trolley = new Trolley(distCenter, 1000);

        Product product_1 = new Product(200, "Handy", 200);
        Product product_2 = new Product(123, "Beer", 300);
        Product product_3 = new Product(431, "BigStone", 500);
        Product product_4 = new Product(4711, "MooreBeer", 500);

        if (trolley.load(product_1)) {
            Product product = trolley.getProduct(product_1.getId());

            if (product != null) {
                System.out.println(product.getName() + " loaded.");
            }
        }
        if (trolley.load(product_2)) {
            Product product = trolley.getProduct(product_2.getId());

            if (product != null) {
                System.out.println(product.getName() + " loaded.");
            }
        }

        if (trolley.move(Direction.SOUTH)) {
            System.out.println("\nTrolley moved 1 field South.\ncurrent posX: " + trolley.getPosition()[0] + " posY: " + trolley.getPosition()[1] + "\n");
        }


        if (trolley.load(product_3)) {
            Product product = trolley.getProduct(product_3.getId());

            if (product != null) {
                System.out.println(product.getName() + " loaded.");
            }
        } else {
            if (trolley.move(Direction.NORTH)) {
                System.out.println("\nTrolley moved 1 field North.\ncurrent posX: " + trolley.getPosition()[0] + " posY: " + trolley.getPosition()[1] + "\n");
            }

            if (trolley.load(product_3)) {
                Product product = trolley.getProduct(product_3.getId());

                if (product != null) {
                    System.out.println(product.getName() + " loaded.");
                }
            }
        }

        if (trolley.load(product_4)) {
            Product product = trolley.getProduct(product_4.getId());

            if (product != null) {
                System.out.println(product.getName() + " loaded.");
            }
        } else {
            if (trolley.unload(product_4.getId())) {
                Product product = trolley.getProduct(product_4.getId());

                if (product != null) {
                    System.out.println(product.getName() + " unloaded.");
                }
            } else {
                if (trolley.move(Direction.EAST)) {
                    System.out.println("\nTrolley moved 1 field East.\ncurrent posX: " + trolley.getPosition()[0] + " posY: " + trolley.getPosition()[1] + "\n");
                } else {
                    System.out.println("\nTrolley can not move East, Obstacle in the way.\ncurrent posX: " + trolley.getPosition()[0] + " posY: " + trolley.getPosition()[1] + "\n");
                }

                if (trolley.move(Direction.SOUTH)) {
                    System.out.println("\nTrolley moved 1 field South.\ncurrent posX: " + trolley.getPosition()[0] + " posY: " + trolley.getPosition()[1] + "\n");
                }
                if (trolley.move(Direction.EAST)) {
                    System.out.println("\nTrolley moved 1 field East.\ncurrent posX: " + trolley.getPosition()[0] + " posY: " + trolley.getPosition()[1] + "\n");
                }

                if (trolley.unload(product_4.getId())) {
                    Product product = trolley.getProduct(product_4.getId());

                    if (product != null) {
                        System.out.println(product.getName() + " unloaded.");
                    }
                }


                if (trolley.unload(product_3.getId())) {
                    Product product = trolley.getProduct(product_3.getId());

                    if (product != null) {
                        System.out.println(product.getName() + " unloaded.");
                    }
                }

                if (trolley.move(Direction.WEST)) {
                    System.out.println("\nTrolley moved 1 field West.\ncurrent posX: " + trolley.getPosition()[0] + " posY: " + trolley.getPosition()[1] + "\n");
                }
                if (trolley.move(Direction.NORTH)) {
                    System.out.println("\nTrolley moved 1 field North.\ncurrent posX: " + trolley.getPosition()[0] + " posY: " + trolley.getPosition()[1] + "\n");
                }

                if (trolley.load(product_4)) {
                    System.out.println(trolley.getProduct(product_4.getId()).getName() + " loaded.");
                }
            }
        }

        trolley.unloadAll();

        if (trolley.move(Direction.SOUTH)) {
            System.out.println("\nTrolley moved 1 field South.\ncurrent posX: " + trolley.getPosition()[0] + " posY: " + trolley.getPosition()[1] + "\n");
        }
        if (trolley.move(Direction.EAST)) {
            System.out.println("\nTrolley moved 1 field East.\ncurrent posX: " + trolley.getPosition()[0] + " posY: " + trolley.getPosition()[1] + "\n");
        }

        trolley.unloadAll();
    }
}
