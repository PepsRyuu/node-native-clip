// hello.cc
#include <node.h>
#include "clip.h"

namespace NodeClip {

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;
    using v8::Exception;

    void SetText(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();

        if (args.Length() < 1 || !args[0]->IsString()) {
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Invalid argument provided. Must be of type string.")));
            return;
        }

        std::string value(*String::Utf8Value(args[0]->ToString()));
        clip::set_text(value);
    }

    void GetText(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        std::string value;
        clip::get_text(value);
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, value.c_str()));
    }

    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, "setText", SetText);
        NODE_SET_METHOD(exports, "getText", GetText);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

} 