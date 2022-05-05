#include <windows.h>

#define ID_OK_BTN    2000
#define ID_OK_BTN1    2001    // ���� ������ �߰��� ��ư    // ���� 2�� �߰�
#define ID_OK_BTN2    2002    // ���ϵ� ������ �߰��� ��ư

HINSTANCE g_hInst;
LPCTSTR lpszClass = L"HelloAPI";
LPCTSTR ChildClassName = L"ChildWin";
LPCTSTR ChildClassName2 = L"ChildWin2";    // �߰�


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChildWndProc2(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); // 

int APIENTRY WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpszCmdParam,
    int nCmdShow)
{
    HWND hWnd;
    MSG Message;
    WNDCLASS WndClass;
    WNDCLASS WndClass2;
    g_hInst = hInstance;

    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hInstance = hInstance;
    WndClass.lpfnWndProc = (WNDPROC)WndProc;
    WndClass.lpszClassName = lpszClass;
    WndClass.lpszMenuName = NULL;
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&WndClass);     //���������� Ŭ���� ���

    WndClass2.cbClsExtra = 0;
    WndClass2.cbWndExtra = 0;
    WndClass2.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    WndClass2.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass2.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass2.hInstance = hInstance;
    WndClass2.lpfnWndProc = (WNDPROC)WndProc;
    WndClass2.lpszClassName = lpszClass;
    WndClass2.lpszMenuName = NULL;
    WndClass2.style = CS_HREDRAW | CS_VREDRAW;




    WndClass.lpfnWndProc = ChildWndProc;      //���ϵ� ������ ���ν���
    WndClass.lpszClassName = ChildClassName; //���ϵ� ������ Ŭ�����̸�
    RegisterClass(&WndClass);

    WndClass2.lpfnWndProc = ChildWndProc2;      //���ϵ� ������ ���ν���        // ���� 3�� �߰�
    WndClass2.lpszClassName = ChildClassName2; //���ϵ� ������ Ŭ�����̸�
    RegisterClass(&WndClass2);

    hWnd = CreateWindow(lpszClass,            //������Ŭ���� �̸�
        L"Visual C++ �⼮���� ��ü �ǽ�������",                //������Ÿ��Ʋ
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,   //�����콺Ÿ��
        200, 200,                            //�����찡 ���϶� X Y��ǥ
        800, 600,                            //�������� ���� ����                
        (HWND)NULL,                            //�θ������� �ڵ�
        (HMENU)NULL,                        //�����찡 ������ �޴��ڵ�
        hInstance,                            //�ν��Ͻ��ڵ�
        NULL);                                //������ ������

    ShowWindow(hWnd, nCmdShow);

    while (GetMessage(&Message, 0, 0, 0)) {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }
    return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage,
    WPARAM wParam, LPARAM lParam)
{
    LPCTSTR text = L"Visual C++ ���α׷��� ������";
    LPCTSTR text2 = L"202134-154039 ������";                        // �й�, �̸�
    switch (iMessage) {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        TextOut(hdc, 100, 100, text, lstrlen(text));    // 1�� ��������
        TextOut(hdc, 100, 120, text2, lstrlen(text2));    // 2�� �й�, ����
        EndPaint(hWnd, &ps);
        return 0;
    }
    case WM_CREATE:
    {
        HWND hChildWnd = CreateWindow(
            ChildClassName,             // ���ϵ� ������ Ŭ���� �̸� 
            L"�⼮����",                // ������ Ÿ��Ʋ 
            WS_OVERLAPPEDWINDOW | WS_CHILD,  // ������  ��Ÿ�� 
            50,               // ������ ���� �� x ��ǥ 
            150,               // ������ ���� �� y ��ǥ 
            260,               // ������ ��
            200,               // ������ ����
            hWnd,                 // �θ� ������
            (HMENU)1000,            // ���ϵ� ������ID 
            g_hInst,                   // �ν��Ͻ� �ڵ� 
            (LPVOID)NULL);          // ������ ������            

        ShowWindow(hChildWnd, SW_SHOW);

        hChildWnd = CreateWindow(
            ChildClassName2,             // �߰��Ǵ� ���ϵ� ������ Ŭ���� �̸� 
            L"�Ҽ�",
            WS_OVERLAPPEDWINDOW | WS_CHILD,
            400,
            150,
            260,
            200,               // ������ ����
            hWnd,                 // �θ� ������
            (HMENU)1100,            // ���ϵ� ������ID     
            g_hInst,                   // �ν��Ͻ� �ڵ� 
            (LPVOID)NULL);          // ������ ������            

        ShowWindow(hChildWnd, SW_SHOW);

        hChildWnd = CreateWindow(
            L"button",                // ������ Ŭ���� �̸� 
            L"��ü������",            // ������ Ÿ��Ʋ 
            WS_CHILD | WS_VISIBLE,     // ������ ��Ÿ�� 
            100,               // ������ ���� �� x ��ǥ 
            400,               // ������ ���� �� y ��ǥ 
            150,               // ������ ��
            30,               // ������ ����
            hWnd,                 // �θ� ������
            (HMENU)ID_OK_BTN,       // ��Ʈ�� ID
            g_hInst,                   // �ν��Ͻ� �ڵ� 
            (LPVOID)NULL);          // ������ ������

        if (!hChildWnd)     return -1;

        hChildWnd = CreateWindow(                    // �߰��� ��ư
            L"button",                // ������ Ŭ���� �̸� 
            L"�а�",            // ������ Ÿ��Ʋ
            WS_CHILD | WS_VISIBLE,     // ������ ��Ÿ�� 
            500,               // ������ ���� �� x ��ǥ 
            400,               // ������ ���� �� y ��ǥ 
            100,               // ������ ��
            30,               // ������ ����
            hWnd,                 // �θ� ������
            (HMENU)ID_OK_BTN1,       // ��Ʈ�� ID
            g_hInst,                   // �ν��Ͻ� �ڵ� 
            (LPVOID)NULL);          // ������ ������

        if (!hChildWnd)     return -1;
        return 0;
    }

    case WM_COMMAND:
    {
        if (LOWORD(wParam) == ID_OK_BTN)
        {
            MessageBox(hWnd, L"2022�� 5�� 16�� 18:00����", L"��ü������", MB_OK);
        }

        if (LOWORD(wParam) == ID_OK_BTN1)        // ���������� �߰��� ��ư
        {
            MessageBox(hWnd, L"��ǻ�Ͱ��а�", L"�а�", MB_OK);
        }

        return 0;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    LPCTSTR text = L"���� �Ұ���";
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        TextOut(hdc, 10, 10, text, lstrlen(text));
        EndPaint(hWnd, &ps);
        return 0;
    }

    case WM_CREATE:
    {
        HWND hChildWnd = CreateWindow(                    // �߰��� ��ư
            L"button",                // ������ Ŭ���� �̸� 
            L"��ü��������",            // ������ Ÿ��Ʋ
            WS_CHILD | WS_VISIBLE,     // ������ ��Ÿ�� 
            50,               // ������ ���� �� x ��ǥ 
            100,               // ������ ���� �� y ��ǥ 
            100,               // ������ ��
            30,               // ������ ����
            hWnd,                 // �θ� ������
            (HMENU)ID_OK_BTN2,       // ��Ʈ�� ID
            g_hInst,                   // �ν��Ͻ� �ڵ� 
            (LPVOID)NULL);          // ������ ������

        if (!hChildWnd)     return -1;

        return 0;
    }

    case WM_COMMAND:
    {
        if (LOWORD(wParam) == ID_OK_BTN2)
        {
            MessageBox(hWnd, L"�ǽ�������", L"��ü��������", MB_OK);        //�а�
        }

        return 0;
    }
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT CALLBACK ChildWndProc2(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)    // �߰��� CALLBACK�Լ�
{
    LPCTSTR text = L"������������ �����н�����";
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        TextOut(hdc, 10, 10, text, lstrlen(text));
        EndPaint(hWnd, &ps);

        return 0;
    }
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}