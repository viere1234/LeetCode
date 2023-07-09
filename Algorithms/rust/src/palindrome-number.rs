impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        let num_string = x.to_string();
        return num_string.chars().eq(num_string.chars().rev())
    }
}