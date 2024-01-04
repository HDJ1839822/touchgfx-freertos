#include "app_config.h"



/*use cmsis cjson pack v1.7.7*/

#include "cJSON.h"  // cJSON库的头文件
#include "bsp_usart.h"  // UART驱动的头文件，具体驱动根据您的硬件和开发环境而定

// 函数声明
void sendJsonDataViaUART(cJSON *jsonObject);

int test_cjson_send() {
    // 创建一个简单的JSON对象
    cJSON *jsonObject = cJSON_CreateObject();
  

    // 添加基本信息
    cJSON_AddStringToObject(jsonObject, "name", "John Doe");
    cJSON_AddNumberToObject(jsonObject, "age", 30);
    cJSON_AddStringToObject(jsonObject, "city", "New York");

    // 添加布尔值
    cJSON_AddFalseToObject(jsonObject, "isStudent");

    // 添加数组
    cJSON *gradesArray = cJSON_CreateArray();
    cJSON_AddItemToArray(gradesArray, cJSON_CreateNumber(90));
    cJSON_AddItemToArray(gradesArray, cJSON_CreateNumber(85));
    cJSON_AddItemToArray(gradesArray, cJSON_CreateNumber(92));
    cJSON_AddItemToObject(jsonObject, "grades", gradesArray);

    // 添加嵌套的对象
    cJSON *addressObject = cJSON_CreateObject();
    cJSON_AddStringToObject(addressObject, "street", "123 Main St");
    cJSON_AddStringToObject(addressObject, "city", "Anytown");
    cJSON_AddStringToObject(addressObject, "zipCode", "12345");
    cJSON_AddItemToObject(jsonObject, "address", addressObject);
   
    // 调用发送函数
    sendJsonDataViaUART(jsonObject);

    // 释放JSON对象
    cJSON_Delete(jsonObject);

    return 0;
}

// 函数定义
void sendJsonDataViaUART(cJSON *jsonObject) {
    // 将JSON对象转换为字符串
    char *jsonString = cJSON_Print(jsonObject);

    // 假设uart_send函数是您的UART发送函数，具体实现根据您的硬件和驱动而定
    putstr(jsonString);

    // 释放内存
    cJSON_free(jsonString);
}





// 函数声明
cJSON* parseReceivedJsonData(const char *jsonString);


// 模拟接收 UART 数据的函数
const char *receiveJsonDataFromUART() {
    static char receivedData[256];  // 假设接收缓冲区大小为 256 字节
    printf("Enter JSON data: ");
    scanf("%255s", receivedData);  // 限制输入字符串长度，防止缓冲区溢出
    return receivedData;
}

int test_cjson_receive() {
    // 假设 receiveJsonDataFromUART 函数是您的UART接收函数，返回接收到的JSON字符串
    const char *receivedJsonString = receiveJsonDataFromUART();

    // 解析接收到的JSON字符串
    cJSON *receivedJsonObject = parseReceivedJsonData(receivedJsonString);

    // 处理解析后的JSON对象，例如读取其中的数据
    if (receivedJsonObject != NULL) {
        cJSON *nameItem = cJSON_GetObjectItem(receivedJsonObject, "name");
        if (nameItem != NULL && nameItem->type == cJSON_String) {
            printf("Received Name: %s\n", nameItem->valuestring);
        }

        // 释放解析后的JSON对象
        cJSON_Delete(receivedJsonObject);
    }

    return 0;
}

// 函数定义
cJSON* parseReceivedJsonData(const char *jsonString) {
    // 使用 cJSON_Parse 函数解析JSON字符串
    cJSON *jsonObject = cJSON_Parse(jsonString);

    // 检查解析是否成功
    if (jsonObject == NULL) {
        const char *errorPtr = cJSON_GetErrorPtr();
        if (errorPtr != NULL) {
            printf("JSON Parsing Error: %s\n", errorPtr);
        }
    }

    return jsonObject;
}



