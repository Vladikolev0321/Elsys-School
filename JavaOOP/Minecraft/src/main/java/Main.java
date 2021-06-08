import org.lwjgl.glfw.GLFWErrorCallback;

public class Main {
    private void run(){
        init();

        mainLeop();

        cleanup();
    }

    private void init() {
        GLFWErrorCallback.createPrint(System.err).set();
        glfwinit();
    }

    private void mainLeop() {
    }
    private void cleanup() {
    }

    public static void main(String[] args){
        new Main().run();
    }
}
