#pragma once

template <typename T, typename U> T fn(U obj);
template <typename U> void  fn<void,U>(U obj);