package applications;

public class AppManager {

    void foo(){
        System.out.println("foo method");
    }

    public static class AppBuilder<UnknownClass>{

        public interface AppCallBacks<UnknownClass>{
            public UnknownClass onSuccess();
            public UnknownClass onFailed();
        }

        private Class<UnknownClass> unknownClass;
        private String name;
        private int age;
        private AppCallBacks<UnknownClass> appCallBacks;

        AppBuilder<UnknownClass> AppBuilder(){
            return this;
        }

        AppBuilder<UnknownClass> withInputAppCallBacks(AppCallBacks<UnknownClass> appCallBacks){
            this.appCallBacks = appCallBacks;
            return this;
        }

        AppBuilder<UnknownClass> withInputClass(Class<UnknownClass> unknownClass){
            this.unknownClass = unknownClass;
            return this;
        }

        AppBuilder<UnknownClass> withInputName(String s){
            this.name = s;
            return this;
        }

        AppBuilder<UnknownClass> withInputAge(int age){
            this.age = age;
            return this;
        }

        void bar(){
            this.appCallBacks.onSuccess();
        }

    }
}
