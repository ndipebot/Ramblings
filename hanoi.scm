(define (start-hanoi total tower1 tower2 tower3)
;;TUPLE ABSTRACTION FOR PRINTING
(define (make-tupe name values)
  (list name values))

(define (tail-tupe tuple n)
  (list-tail (cadr tuple) n))

(define (head-tupe tuple n)
  (list-head (cadr tuple) n))

(define (tupe-values tuple)
  (cadr tuple))

(define (print-tupe-name tuple)
  (display (car tuple)))

(define (print-tupe-contents tuple)
  (display (cadr tuple)))

(define (print-tupe-first tuple)
  (display (caadr tuple)))

(define (append-tupe values tuple)
  (make-tupe (car tuple) (append values (cadr tuple))))



(define (print-move from to)
  (display "MOVE ")
  (print-tupe-first from)
  (display " FROM ")
  (print-tupe-name from)
  (display " TO ")
  (print-tupe-name to)
  (newline))


(define (hanoi n from to spare)
  (cond ((= n 0) "DONE")
        (else
         (hanoi (1- n) (make-tupe (car from) (head-tupe from (1- n))) spare to)
         (print-move (make-tupe (car from) (tail-tupe from (1- n))) to)

         (hanoi (1- n)
                (make-tupe (car spare) (append (head-tupe from (1- n)) (tupe-values spare)))
                (make-tupe (car to) (append (tail-tupe from (1- n)) (tupe-values to)))
                (make-tupe (car from) '())))))


  (hanoi total (make-tupe "TOWER1" tower1) (make-tupe "TOWER3" tower3) (make-tupe "TOWER2" tower2)))
