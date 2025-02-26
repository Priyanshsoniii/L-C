class Book {

     function getTitle() {
        return $this->title;
    }

     function getAuthor() {
        return $this->author;
    }

     function turnPage() {
        $this->currentPage++;
    }

     function getCurrentPage() {
        return "Content of page ";
    }

     function getLocation() {
        // returns the position in the library
        // ie. shelf number & room number
    }
}

interface BookStorage {
    function save(Book $book);
}


class FileBookStorage implements BookStorage {
     function save(Book $book) {
        $filename = '/documents/' . $book->getTitle() . ' - ' . $book->getAuthor();
        file_put_contents($filename, serialize($book));
    }
}


interface Printer {
     function printPage($page);
}


class PlainTextPrinter implements Printer {
     function printPage($page) {
        echo $page;
    }
}


class HtmlPrinter implements Printer {
     function printPage($page) {
        echo '<div style="single-page">' . ($page) . '</div>';
    }
}
