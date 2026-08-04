if (type == 1) {
    int x, y;
    scanf("%d %d", &x, &y);

    // 1. Increment the book count for shelf x
    *(total_number_of_books + x) += 1;

    // 2. Reallocate memory for shelf x to fit the new book
    *(total_number_of_pages + x) = (int*) realloc(
        *(total_number_of_pages + x), 
        (*(total_number_of_books + x)) * sizeof(int)
    );

    // 3. Store the page count y at the last index of shelf x
    *(*(total_number_of_pages + x) + *(total_number_of_books + x) - 1) = y;
}
