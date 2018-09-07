{
  "targets": [{
    "target_name": "NodeNativeClip",
    "include_dirs" : [
      "src",
      "cpp_modules/clip"
    ],
    "sources": [
      "src/index.cc",
      "cpp_modules/clip/clip.cpp",
      "cpp_modules/clip/image.cpp"
    ],
    "conditions": [
        ["OS=='linux'", {
            "sources": [ "cpp_modules/clip/clip_x11.cpp"]
        }],

        ["OS=='mac'", {
            "sources": [ "cpp_modules/clip/clip_osx.mm"]
        }],

        ["OS=='win'", {
            "sources": [ "cpp_modules/clip/clip_win.cpp"]
        }]
    ]
  }]
}