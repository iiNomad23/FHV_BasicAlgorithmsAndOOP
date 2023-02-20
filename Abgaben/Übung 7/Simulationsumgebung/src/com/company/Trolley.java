package com.company;

import com.company.enums.Direction;
import com.company.enums.FieldType;

import java.util.ArrayList;

/**
 * The class describes a Trolley with basic functions.
 *
 * @author Prescher Marco
 */
public class Trolley {
    private final double maxWeight;
    private final ArrayList<Product> loadedProducts;
    private final DistributionCenter distributionCenter;
    private int posX;
    private int posY;

    public Trolley(DistributionCenter distributionCenter, double maxWeight) {
        this.maxWeight = maxWeight;
        this.loadedProducts = new ArrayList<Product>();

        this.distributionCenter = distributionCenter;

        this.posX = 0;
        this.posY = 0;
    }

    public double calcWeight() {
        double weight = 0;
        for (Product item : this.loadedProducts) {
            weight += item.getWeight();
        }

        return weight;
    }

    public boolean productExist(Product product) {
        int id = product.getId();
        for (Product loadedProduct : this.loadedProducts) {
            if (loadedProduct.getId() == id) {
                return true;
            }
        }

        return false;
    }

    public boolean productExist(int id) {
        for (Product loadedProduct : this.loadedProducts) {
            if (loadedProduct.getId() == id) {
                return true;
            }
        }

        return false;
    }

    public boolean load(Product product) {
        if (this.distributionCenter.getFieldType(this.posX, this.posY) == FieldType.LOADING_STATION) {
            if (!this.productExist(product)) {
                if ((this.calcWeight() + product.getWeight()) <= this.maxWeight) {
                    this.loadedProducts.add(product);
                    return true;
                } else {
                    System.out.println("Weight exceeded.");
                }
            } else {
                System.out.println("Product already exist.");
            }
        } else {
            System.out.println("No loading station.");
        }

        return false;
    }

    public boolean unload(int id) {
        if (this.distributionCenter.getFieldType(this.posX, this.posY) == FieldType.UNLOADING_STATION) {
            if (this.productExist(id)) {
                int listIndex = -1;
                for (int i = 0; i < this.loadedProducts.size(); i++) {
                    if (this.loadedProducts.get(i).getId() == id) {
                        listIndex = i;
                    }
                }

                if (listIndex >= 0) {
                    this.loadedProducts.remove(listIndex);
                    return true;
                } else {
                    System.out.println("List index not found.");
                }
            } else {
                System.out.println("Product does not exist.");
            }
        } else {
            System.out.println("No unloading station.");
        }

        return false;
    }

    public void unloadAll() {
        if (this.distributionCenter.getFieldType(this.posX, this.posY) == FieldType.UNLOADING_STATION) {
            if (!this.loadedProducts.isEmpty()) {
                System.out.println("Unload: " + this.loadedProducts.get(0).getName());

                this.loadedProducts.remove(0);
                this.unloadAll();
            } else {
                System.out.println("All products unloaded.");
            }
        } else {
            System.out.println("No unloading station.");
        }
    }

    public int[] getPosition() {
        return new int[]{this.posX, this.posY};
    }

    public Product getProduct(int id) {
        for (Product loadedProduct : this.loadedProducts) {
            if (loadedProduct.getId() == id) {
                return loadedProduct;
            }
        }

        return null;
    }

    public boolean move(Direction direction) {
        switch (direction) {
            case EAST:
                if (this.distributionCenter.getFieldType(this.posX + 1, this.posY) != FieldType.OBSTACLE) {
                    this.posX += 1;
                    return true;
                }

                break;

            case WEST:
                if (this.posX > 0) {
                    if (this.distributionCenter.getFieldType(this.posX - 1, this.posY) != FieldType.OBSTACLE) {
                        this.posX -= 1;
                        return true;
                    }
                } else {
                    System.out.println("Trolley has no way to drive, no Field at this Position.");
                }

                break;

            case SOUTH:
                if (this.distributionCenter.getFieldType(this.posX, this.posY + 1) != FieldType.OBSTACLE) {
                    this.posY += 1;
                    return true;
                }

                break;

            case NORTH:
                if (this.posY > 0) {
                    if (this.distributionCenter.getFieldType(this.posX, this.posY - 1) != FieldType.OBSTACLE) {
                        this.posY -= 1;
                        return true;
                    }
                } else {
                    System.out.println("Trolley has no way to drive, no Field at this Position.");
                }

                break;
        }

        return false;
    }

    @Override
    public String toString() {
        return "xPos: " + this.posX + "\tyPos: " + this.posY + "\titemsLoaded: " + this.loadedProducts.size();
    }
}
