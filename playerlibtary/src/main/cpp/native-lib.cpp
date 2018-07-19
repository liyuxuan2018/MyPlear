#include <jni.h>
#include <string>
#include <android/log.h>
extern  "C"{
#include <libavformat/avformat.h>
}
#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"ywl5320",FORMAT,##__VA_ARGS__);


JNIEXPORT jstring JNICALL
Java_com_example_modelplayer_Demo_stringFromJNI(JNIEnv *env, jobject instance) {

    // TODO
    std::string hello = "Hello from demo++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_playerlibtary_Demo_stringFromJNI(JNIEnv *env, jobject instance) {
    av_register_all();
    AVCodec *c_temp = av_codec_next(NULL);
    while (c_temp != NULL)
    {
        switch (c_temp->type)
        {
            case AVMEDIA_TYPE_VIDEO:
                LOGI("[Video]:%s", c_temp->name);
                break;
            case AVMEDIA_TYPE_AUDIO:
                LOGI("[Audio]:%s", c_temp->name);
                break;
            default:
                LOGI("[Other]:%s", c_temp->name);
                break;
        }
        c_temp = c_temp->next;
    }
    // TODO
    std::string hello = "Hello from demo++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_lls_1a_myplear_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {



    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
