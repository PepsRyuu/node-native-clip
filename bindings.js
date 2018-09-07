let entry;

if (process.env.DEBUG) {
  entry = require('./build/Debug/NodeNativeClip.node');
} else {
  entry= require('./build/Release/NodeNativeClip.node');
}

module.exports = entry;