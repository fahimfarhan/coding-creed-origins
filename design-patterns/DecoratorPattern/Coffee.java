public interface Coffee{
    public double getCost();
    public String getIngredients();
}

class SimpleCoffee implements Coffee{
    public double getCost(){
        return 1;
    }
    public String getIngredients(){
        return "SimpleCoffee";
    }
}