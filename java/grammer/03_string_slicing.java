class GN03StringSlicing {
    public static void main(String[] args) {
        String text = "algorithm";
        System.out.println("앞 4글자: " + text.substring(0, 4));
        System.out.println("뒤 3글자: " + text.substring(text.length() - 3));
        System.out.println("역순: " + new StringBuilder(text).reverse());
    }
}
