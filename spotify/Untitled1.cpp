#include <iostream>
#include <Windows.h>

// Función que maneja los mensajes de la ventana
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Punto de entrada del programa
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Creamos la ventana principal
    HWND hwnd;
    WNDCLASSEX wc;
    ZeroMemory(&wc, sizeof(wc));
    wc.cbSize = sizeof(wc);
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = "FormWindowClass";
    wc.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClassEx(&wc);
    hwnd = CreateWindowEx(0, "FormWindowClass", "Formulario de registro", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 500, 300, NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, nCmdShow);

    // Creamos los controles del formulario
    HWND nameLabel = CreateWindow("STATIC", "Nombre:", WS_VISIBLE | WS_CHILD, 20, 20, 80, 25, hwnd, NULL, hInstance, NULL);
    HWND nameEdit = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 100, 20, 200, 25, hwnd, NULL, hInstance, NULL);
    HWND emailLabel = CreateWindow("STATIC", "Correo electrónico:", WS_VISIBLE | WS_CHILD, 20, 60, 120, 25, hwnd, NULL, hInstance, NULL);
    HWND emailEdit = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 60, 200, 25, hwnd, NULL, hInstance, NULL);
    HWND submitButton = CreateWindow("BUTTON", "Enviar", WS_VISIBLE | WS_CHILD, 20, 100, 80, 25, hwnd, NULL, hInstance, NULL);

    // Bucle de mensajes de la ventana
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Función que maneja los mensajes de la ventana
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
