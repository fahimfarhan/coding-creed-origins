public abstract class CoffeeDecorator implements Coffee{
    protected final Coffee decoratedCoffee;
    public CoffeeDecorator(Coffee c) {
        this.decoratedCoffee = c;
    }

    public double getCost() { // Implementing methods of the interface
        return decoratedCoffee.getCost();
    }

    public String getIngredients() {
        return decoratedCoffee.getIngredients();
    }


}

class WithMilk extends CoffeeDecorator {
    public WithMilk(Coffee c){
        super(c);
    }

    public double getCost(){
        return super.getCost() + 0.5;
    }

    public String getIngredients(){
        return super.getIngredients() + " with milk!";
    }


}

// Decorator WithSprinkles mixes sprinkles onto coffee.
// Note it extends CoffeeDecorator.
class WithSprinkles extends CoffeeDecorator {
    public WithSprinkles(Coffee c) {
        super(c);
    }

    public double getCost() {
        return super.getCost() + 0.2;
    }

    public String getIngredients() {
        return super.getIngredients() + ", Sprinkles";
    }
}