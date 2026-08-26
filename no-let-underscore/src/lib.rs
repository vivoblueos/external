#![no_std]

pub trait IgnoreResult {
    fn ignore_result(self)
    where
        Self: Sized,
    {
    }
}
pub trait IgnoreAny {
    fn ignore_old_value(self)
    where
        Self: Sized,
    {
    }
}

impl<T, E> IgnoreResult for core::result::Result<T, E> {}
impl<T> IgnoreAny for T {}
