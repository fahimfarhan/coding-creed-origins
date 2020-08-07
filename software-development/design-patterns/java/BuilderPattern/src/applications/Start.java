package applications;

public class Start {
    public static void main(String[] Args) {
        AppManager.AppBuilder<Model> appBuilder = new AppManager.AppBuilder<Model>()
                .withInputAge(1)
                .withInputClass(Model.class)
                .withInputName("John Doe")
                .withInputAppCallBacks(new AppManager.AppBuilder.AppCallBacks<Model>() {
                    @Override
                    public Model onSuccess() {
                        Model model = new Model();
                        System.out.println(model.toString());
                        return model;
                    }

                    @Override
                    public Model onFailed() {
                        Model model = new Model();
                        model.firstName= "failed ";
                        model.lastName = "failed ";
                        System.out.println(model.toString());
                        return model;
                    }
                });

        appBuilder.bar();
    }
}
