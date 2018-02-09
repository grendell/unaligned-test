#include <jni.h>
#include <string>
#include <cstdlib>

void * operator new(size_t size) {
    void * p = malloc(size + 1);
    p = (void *) ((char *) p + 1);

    return p;
}

void operator delete(void * p) {
    p = (void *) ((char *) p - 1);
    free(p);
}

extern "C" JNIEXPORT jlong JNICALL
Java_com_grendell_unaligned_MainActivity_unalignedTest(JNIEnv *, jclass) {
    int * i = new int[3];
    i[0] = 6;
    i[1] = 9;
    i[2] = i[0] * i[1]; // 42
    delete[] i;
    return (jlong) i;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_grendell_unaligned_MainActivity_getArch(JNIEnv * env, jclass) {
#if defined(__arm__)
#if defined(__ARM_ARCH_7A__)
#define ABI "armeabi-v7a"
#else
#define ABI "armeabi"
#endif
#elif defined(__i386__)
#define ABI "x86"
#elif defined(__x86_64__)
#define ABI "x86_64"
#elif defined(__mips64)
#define ABI "mips64"
#elif defined(__mips__)
#define ABI "mips"
#elif defined(__aarch64__)
#define ABI "arm64-v8a"
#else
#define ABI "unknown"
#endif

    return env->NewStringUTF(ABI);
}