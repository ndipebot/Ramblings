(define (start-hanoi tower1)
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

(define (append-tupe values tuple)sd
  (make-tupe (car tuple) (append values (cadr tuple))))



(define (print-move from to)
  (display "MOVE ")
  (print-tupe-first from)
  (display " FROM ")
  (print-tupe-name from)
  (display " TO ")`
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

(define (count n)
  (define (count-iter n counter)
   (cond ((null? n) counter)
         (else (count-iter (cdr n)
                           (1+ counter)))))
  (count-iter n 0))


  (hanoi (count tower1) (make-tupe "TOWER1" tower1) (make-tupe "TOWER3" '()) (make-tupe "TOWER2" '())))
