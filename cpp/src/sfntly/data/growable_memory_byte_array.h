/*
 * Copyright 2011 Google Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TYPOGRAPHY_FONT_SFNTLY_SRC_SFNTLY_DATA_GROWABLE_MEMORY_BYTE_ARRAY_H_
#define TYPOGRAPHY_FONT_SFNTLY_SRC_SFNTLY_DATA_GROWABLE_MEMORY_BYTE_ARRAY_H_

#include "sfntly/data/byte_array.h"

namespace sfntly {

// Note: this is not really a port of Java version. Instead, this wraps a
//       std::vector inside and let it grow by calling resize()
class GrowableMemoryByteArray : public ByteArray,
                                public RefCounted<GrowableMemoryByteArray> {
 public:
  GrowableMemoryByteArray();
  virtual ~GrowableMemoryByteArray();

 protected:
  virtual bool InternalPut(int32_t index, byte_t b);
  virtual int32_t InternalPut(int32_t index,
                              ByteVector* b,
                              int32_t offset,
                              int32_t length);
  virtual byte_t InternalGet(int32_t index);
  virtual int32_t InternalGet(int32_t index,
                              ByteVector* b,
                              int32_t offset,
                              int32_t length);
  virtual void Close();
  virtual byte_t* Begin();

 private:
  ByteVector b_;
};

}  // namespace sfntly

#endif  // TYPOGRAPHY_FONT_SFNTLY_SRC_SFNTLY_DATA_GROWABLE_MEMORY_BYTE_ARRAY_H_
